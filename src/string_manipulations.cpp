//Functions required for manipulating strings
//Version History:	12/16/05: Created
//					12/26/05: Added string_search_replace function
//					12/27/05: Added string_find function
//					02/14/06: Changed comments
//					06/21/06: Added split_tab.  Cast size_t item to int to avoid warnings.
//					07/19/06: Added int_to_string
//					09/15/06: Added has_alnum function
//					07/11/08: Updated some bug fixes to make it work in Visual Studio 2008 (string_find function)

//PERTINENT LIBRARIES
#include <string>				//string
#include <stdexcept>			//domain_error
#include <iostream>				//cerr
#include <vector>				//vector
#include <algorithm>			//find_if
#include <sstream>				//string stream
#include <cctype>				//isalpha
#include "bool_is_char_blank.h"	//is_not_tab

//USING DECLARATIONS
using std::string;
using std::domain_error;
using std::cerr;
using std::endl;
using std::cout;
using std::vector;
using std::find_if;
using std::stringstream;
using std::isalnum;


//------------------------------------------------------------------------------------------------------
//---------------------------------GLOBAL FUNCTIONS-----------------------------------------------------
//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------
//STRING_TO_CHAR_ARRAY	
//
//Convert a string to a char array
//
//INPUT:		-string = string to be converted
//				-&char = address of char array to fill
//				-size_t = number of elements in char array (typically obtained by sizeof(char_array))
//
//OUTPUT:		-void
//
//SIDE_EFFECTS:	-throws a domain_error is the char array buffer is smaller than the string to be copied.
//------------------------------------------------------------------------------------------------------
void string_to_char_array(string s, char char_array[], size_t char_array_size) {
	int k = 0;						//current index of char_array to write to.

	
	if ((s.size() <= char_array_size)) {
		//convert s to a char array
		for(string::const_iterator it = s.begin(); it != s.end(); it++) {
			char_array[k] = *it;		//recall: char_array[k] = *(char_array+k)
			k++;
		}

	} else {
		//char array buffer is too small, throw error
		throw domain_error("STRING_TO_CHAR_ARRAY: char array is too small!");
	}
}



//------------------------------------------------------------------------------------------------------
//STRING_SEARCH_REPLACE	
//
//Search a string and replace a certain word
//
//INPUT:		-const string& = original string to replace with
//				-const string& = string to look for
//				-const string& = string to replace with
//
//OUTPUT:		-string
//
//SIDE_EFFECTS:	-throws a domain_error
//------------------------------------------------------------------------------------------------------
string string_search_replace(const string& original_string, const string& look_for, const string& replace_with) {
	string ret;												//returned string
	string::const_iterator i = original_string.begin();		//
	string::const_iterator j = original_string.begin();		//
	int look_for_size = (int)look_for.size();					//size of the string to look for
	
	if (look_for_size>0) {
		//find where this occurs
		while (j != original_string.end()) {
			if (*j == look_for[0]) {
				//found a possible match, does the next look_for_size charcters match
				if ((string(j,j+look_for_size) == look_for)) {
					//this is a match.  Write the previous string to the return
					ret = ret + string(i,j);
					
					//now append the replace string
					ret = ret + replace_with;

					//move j past the look_for word
					j = j + look_for_size;
					i = j;
				} else {
					//this is not a match, increment j
					j++;
				}

			} else {
				//this j does not point to a possible match, increment j
				j++;
			}

		}

		//we reached the end, write the ending lines to the return string
		ret = ret + string(i,j);
		
	} else {
		//look_for is empty, throw error.
		throw domain_error("STRING_SEARCH_REPLACE: string to look for and replace is empty");
	}

	return(ret);
}



//------------------------------------------------------------------------------------------------------
//STRING_FIND	
//
//Search a string for a certain word and return an iterator pointing to the start of the first occurence 
//of the word.  If the look_for string is not in the string, returns an iterator pointing to one past 
//the last element of the string.
//
//INPUT:		-const string& = original string to replace with
//				-const string& = string to look for
//
//OUTPUT:		-string::const_iterator
//
//SIDE_EFFECTS:	-throws a domain_error
//------------------------------------------------------------------------------------------------------
string::const_iterator string_find(const string& original_string, const string& look_for) {
	string::const_iterator j	= original_string.begin();			
	int look_for_size			= (int)look_for.size();				//size of the look_for string
	int original_string_size	= (int)original_string.size();		//size of the original string
	int char_position = 0;											//position of j

	if (look_for_size > 0) {
		while(j != original_string.end()) {
			if (*j == look_for[0]) {
				//found a possible match, are there enough characters left to check
				if (char_position > (original_string_size - look_for_size)) {
					//not possible to match look_for any longer (not enough characters left in original_string)
					return(original_string.end());

				} else {
					//enough characters left in original_string, does the next look_for_size charcters match
					if ((string(j,j+look_for_size) == look_for)) {
						//this is a match.
						break;
					} else {
						//increment j
						j++;
						char_position++;
					}	
				}
	
			} else {
				//this j does not point to a possible match, increment j
				j++;
				char_position++;
			}
		}

		return(j);

	} else {
		//look_for string is empty, throw error.
		throw domain_error("STRING_FIND: string to look for is empty.");
	}
}



//------------------------------------------------------------------------------------------------------
//SPLIT_TAB	
//
//Takes a string with words seperated by tabs and splits into a vector<string>
//
//INPUT:		-const string& (The current string to be parsed)
//
//OUTPUT:		-vector<string> (the vector containing the words)
//
//SIDE_EFFECTS:	-throws a domain_error
//------------------------------------------------------------------------------------------------------
vector<string> split_tab(const string& s) {
	string::const_iterator i = s.begin();	//iterator which points to beginning of word
	string::const_iterator j;				//iterator which points to one past end of word
	vector<string> ret;						//vector of words

	while(i!=s.end()) {
		//find first non tab character
		i = find_if(i,s.end(),is_not_tab);

		//find the first tab after word
		j = find_if(i,s.end(),is_tab);

		if (i!=s.end()) {
			ret.push_back(string(i,j));
		}

		i = j;
	}

	return(ret);
}



//------------------------------------------------------------------------------------------------------
//INT_TO_STRING
//
//Converts an int into a string.
//
//INPUT:		-const int&:	int to be converted
//
//OUTPUT:		-string:		int converted to string
//
//SIDE_EFFECTS:	-none
//------------------------------------------------------------------------------------------------------
string int_to_string(const int& input) {
	string ret;
	stringstream ss;

	ss << input;
	ss >> ret;

	return(ret);
}




//------------------------------------------------------------------------------------------------------
//HAS_ALNUM
//
//Checks to see if the string has any alphabetic or numberic characters
//
//INPUT:		-const string&:	string to be checked
//
//OUTPUT:		-bool:			1 if the input string has alphabetic characters, 0 otherwise
//
//SIDE_EFFECTS:	-none
//
//SEE ALSO:		-isalnum
//------------------------------------------------------------------------------------------------------
bool has_alnum(const string& s) {
	
	bool has_alnum;
	string::const_iterator i = s.begin();	//iterator which points to beginning of word

	i = find_if(i,s.end(),isalnum);

	if(i==s.end()) {
		has_alnum = 0;
	} else {
		has_alnum = 1;
	}

	return(has_alnum);
	
}
