//Functions required for my_date
//Version History:	12/16/05: Created:
//					12/19/05: Continued working and compiling with MSVC 6.0
//					12/20/05: Added some member functions to class date
//					12/21/05: Added some member functions to class date
//					12/22/05: Added .date_to_string() member function
//					12/23/05: 
//					12/29/05: Added date_to_string and is_valid_date global functions
//					01/14/06: Added overloaded parse_date function so you can specify the century if the input year is only YY
//					02/09/06: Fixed bug in IS_VALID_DATE where the array indexing was off by 1.
//					02/14/06: Changed comments
//					06/22/06: Added is_same_month_and_year and is_next_month_and_year function
//					07/06/06: Added set_day_to_first_of_month function
//					07/14/06: Added decrement_date_by_one function
//					07/15/06: Added is_between_dates member function
//					07/23/06: Added where_is_date_in_vector function
//					11/01/06: Made date_to_string a const member function
//					07/11/08: Updated date_difference


//PERTINENT LIBRARIES
#include <algorithm>					//find_if
#include <string>						//string
#include <stdexcept>					//domain_error
#include <sstream>						//stringstream
#include "my_date.h"					//date class
#include "bool_is_char_blank.h"			//is_slash, is_not_slash

#include <iostream>

//USING DECLARATIONS
using std::cout;
using std::endl;
using std::string;
using std::domain_error;
using std::find_if;						//This needed to be included for MSVC 6.0
using std::stringstream;
using std::vector;

//------------------------------------------------------------------------------------------------------
//--------------------------------DATE MEMBER FUNCTIONS-------------------------------------------------
//------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------
//DATE	(constructor)	
//
//Constructor for date object created empty.
//
//INPUT:	-none
//
//OUTPUT:	-none
//------------------------------------------------------------------------------------------------------
date::date(): 
month(-1), 
day(-1), 
year(-1) {
}



//------------------------------------------------------------------------------------------------------
//PARSE_DATE	
//
//Parse date into 3 ints of date class.  The year is stored as YYYY.  If the year input is YY, 
//it is assumed to be in the year 20XX.
//
//INPUT:	-string = string of MM/DD/YY or MM/DD/YYYY
//
//OUTPUT:	-void
//------------------------------------------------------------------------------------------------------
void date::parse_date(const string s) {

	string::const_iterator i = s.begin();	//iterator which points to beginning of word
	string::const_iterator j;				//iterator which points to one past end of word
	string current_string;					//the current section of either MM, DD, or YYYY
	int current_column = 1;					//counter to keep track of either month, day, or year string

	while(i!=s.end()) {
		//find first non tab character
		i = find_if(i,s.end(),is_not_slash);

		//find the first tab after word
		j = find_if(i,s.end(),is_slash);

		if(i!=s.end()) {
			//what is the current string?
			current_string = string(i,j);

			switch (current_column) {
				case 1:
					//the string is the M or MM
					if ((current_string.size()==1) || (current_string.size()==2)) {
						month = atoi(current_string.c_str());
					} else {
						throw domain_error("PARSE_DATE: the month must be of the form MM");
					}
					break;

				case 2:
					//the string is the D or DD
					if ((current_string.size()==1) || (current_string.size()==2)) {
						day = atoi(current_string.c_str());
					} else {
						throw domain_error("PARSE_DATE: the day must be of the form DD");
					}
					break;

				case 3:
					//the string is the YY or YYYY
					if (current_string.size() == 4 ) {
						year = atoi(current_string.c_str());
					} else if (current_string.size() == 2) {
						//Assume in the year 20XX
						current_string = "20" + current_string;
						year = atoi(current_string.c_str());
					} else {
						throw domain_error("PARSE_DATE: the year must be of the form YY or YYYY");
					}
					break;

				default:
					throw domain_error("PARSE_DATE: The input string is not of the form xx/xx/xx or xx/xx/xxxx");
			}
		}

		//move iterator forward and increment current word-column
		i = j;
		current_column++;
	}

}



//------------------------------------------------------------------------------------------------------
//PARSE_DATE	
//
//Parse date into 3 ints of date class.  The year is stored as YYYY.  If the year input is YY, 
//one also inputs the century that we wish it to be in.  For example, if the input string is 
//"03/10/85", one would also pass in an additional int of 19 to denote that the correct date is 
//"03/10/1985".
//
//INPUT:	-string = string of MM/DD/YY or MM/DD/YYYY
//			-int = denoting which century the date is in (in range of [0,99]
//
//OUTPUT:	-void
//------------------------------------------------------------------------------------------------------
void date::parse_date(const string s, const int century) {

	string::const_iterator i = s.begin();	//iterator which points to beginning of word
	string::const_iterator j;				//iterator which points to one past end of word
	string current_string;					//the current section of either MM, DD, or YYYY
	int current_column = 1;					//counter to keep track of either month, day, or year string
	stringstream ss;						//used for converting const int century to a string
	string century_string;					//century converted to a string

	//check that century is appropriate
	if (century<0 || century>99) {
		throw domain_error("PARSE_DATE: the century input must be in range [0,99]");
	}

	while(i!=s.end()) {
		//find first non tab character
		i = find_if(i,s.end(),is_not_slash);

		//find the first tab after word
		j = find_if(i,s.end(),is_slash);

		if(i!=s.end()) {
			//what is the current string?
			current_string = string(i,j);

			switch (current_column) {
				case 1:
					//the string is the M or MM
					if ((current_string.size()==1) || (current_string.size()==2)) {
						month = atoi(current_string.c_str());
					} else {
						throw domain_error("PARSE_DATE: the month must be of the form MM");
					}
					break;

				case 2:
					//the string is the D or DD
					if ((current_string.size()==1) || (current_string.size()==2)) {
						day = atoi(current_string.c_str());
					} else {
						throw domain_error("PARSE_DATE: the day must be of the form DD");
					}
					break;

				case 3:
					//the string is the YY or YYYY
					if (current_string.size() == 4 ) {
						year = atoi(current_string.c_str());
					} else if (current_string.size() == 2) {
						//Use the desired century
						ss << century;
						ss >> century_string;
						ss.clear();
						current_string = century_string + current_string;
						year = atoi(current_string.c_str());

					} else {
						throw domain_error("PARSE_DATE: the year must be of the form YY or YYYY");
					}
					break;

				default:
					throw domain_error("PARSE_DATE: The input string is not of the form xx/xx/xx or xx/xx/xxxx");
			}
		}

		//move iterator forward and increment current word-column
		i = j;
		current_column++;
	}

}



//------------------------------------------------------------------------------------------------------
//INCREMENT_DATE_BY_ONE	
//
//Increments the date by 1
//
//INPUT:	-void
//
//OUTPUT:	-void
//------------------------------------------------------------------------------------------------------
void date::increment_date_by_one(void) {

	int month_list[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	//check for leap years
	if (is_leap_year(year)) {
		month_list[1] = 29;
	}

	//increment the date
	if (day != month_list[month-1]) {
		//just increment day
		day++;
	} else if (month != 12) {
		//increment the month and reset the day to 1
		month++;
		day = 1;
	} else {
		//increment the year and reset the month and day to 1
		year++;
		month = 1;
		day = 1;
	}
}



//------------------------------------------------------------------------------------------------------
//DECREMENT_DATE_BY_ONE	
//
//Decrements the date by 1
//
//INPUT:	-void
//
//OUTPUT:	-void
//------------------------------------------------------------------------------------------------------
void date::decrement_date_by_one(void) {

	int month_list[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	//check for leap years
	if (is_leap_year(year)) {
		month_list[1] = 29;
	}

	//decrement the date
	if (day != 1) {
		//just decrement day
		day--;
	} else if (month != 1) {
		//decrement the month and reset the day to last day of the month
		month--;
		day = month_list[month-1];
	} else {
		//decrement the year and reset the month and day to 12/31
		year--;
		month = 12;
		day = 31;
	}
}



//------------------------------------------------------------------------------------------------------
//INCREMENT_TO_FIRST_DAY_OF_NEXT_MONTH	
//
//Increments the date to the first day of the next month.  For example, 3/23/04 goes to 4/1/04.
//
//INPUT:	-void
//
//OUTPUT:	-void
//------------------------------------------------------------------------------------------------------
void date::increment_to_first_day_of_next_month() {

	if (month==12) {
		month = 1;
		day = 1;
		year++;
	} else {
		day = 1;
		month++;
	}
}



//------------------------------------------------------------------------------------------------------
//SET_DAY_TO_FIRST_OF_MONTH	
//
//Sets the day to the first day of the month.  For example, 3/23/04 goes to 3/1/04.
//
//INPUT:	-void
//
//OUTPUT:	-void
//------------------------------------------------------------------------------------------------------
void date::set_day_to_first_of_month() {

	day = 1;
}

//------------------------------------------------------------------------------------------------------
//IS_VALID_DATE	
//
//Checks if the date is valid
//
//INPUT:	-void
//
//OUTPUT:	-bool 1 if date is valid
//				  0 if date is not valid
//------------------------------------------------------------------------------------------------------
bool date::is_valid_date(void) {

	int month_list[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool is_valid = 0;						//flag set to 1 if date is valid

	//check for leap years
	if (is_leap_year(year)) {
		month_list[1] = 29;
	}

	//make sure all month and day are positive (year can be negative to denote BC)
	if (month<=0 || month>12) {
		is_valid = 0;
	} else if (day<=0 || day>month_list[month-1]) {
		is_valid = 0;
	} else {
		//this is a valid date
		is_valid = 1;
	}

	return(is_valid);
}



//------------------------------------------------------------------------------------------------------
//DATE_TO_STRING	
//
//Returns a string representing the current date
//
//INPUT:	-void
//
//OUTPUT:	-string
//------------------------------------------------------------------------------------------------------
string date::date_to_string(void) const {

	stringstream ss;
	string month_string, day_string, year_string, date_string;

	//convert each int to a string
	ss << month;
	ss >> month_string;
	ss.clear();

	ss << day;
	ss >> day_string;
	ss.clear();

	ss << year;
	ss >> year_string;

	//check if the year is less than 1000, if so, we need to add a zero to the front
	if (year<1000) {
		year_string = "0" + year_string;
	}

	//build the date
	date_string = month_string + "/" + day_string + "/" + year_string;

	return(date_string);
}



//------------------------------------------------------------------------------------------------------
//IS_SAME_MONTH_AND_YEAR
//
//Checks to see if the object has the same month and year as the input date
//
//INPUT:	-date:	date to check against to see if month and year are the same
//
//OUTPUT:	-bool
//------------------------------------------------------------------------------------------------------
bool date::is_same_month_and_year(date input_date) {

	bool is_same_month_and_year = 1;

	if (year != input_date.get_year()) {
		is_same_month_and_year = 0;
	}

	if (month != input_date.get_month()) {
		is_same_month_and_year = 0;
	}

	return(is_same_month_and_year);
}



//------------------------------------------------------------------------------------------------------
//IS_NEXT_MONTH_AND_YEAR
//
//Checks to see if the object has the next month and year from the input date
//
//INPUT:	-date:	date to check against to see if month and year are one ahead
//
//OUTPUT:	-bool
//------------------------------------------------------------------------------------------------------
bool date::is_next_month_and_year(date input_date) {

	bool is_next_month_and_year = 1;

	if (input_date.get_month() != 12) {
		//the input date is not December, make sure year stays the same
		if (year != input_date.get_year()) {
			is_next_month_and_year = 0;

		} else if (month != input_date.get_month() + 1)  {
			is_next_month_and_year = 0;
		}

	} else {
		//the input date is december, the object must be january of the next year
		if ((month != 1) && (year != input_date.get_year() + 1)) {
			is_next_month_and_year = 0;
		}
	}

	return(is_next_month_and_year);
}



//------------------------------------------------------------------------------------------------------
//IS_BETWEEN_DATES
//
//Checks to see if the object is in the period defined by two dates.
//
//INPUT:			-date:	start date of period
//					-date:	end date of period
//
//OUTPUT:			-bool
//
//SIDE\-EFFECTS:	-throws a domain error if start date is not before end date
//------------------------------------------------------------------------------------------------------
bool date::is_between_dates(date start_date, date end_date) {

	//make sure start_date is before end_date
	if(date_difference(end_date, start_date)<0) {
		throw domain_error("DATE::IS_BETWEEN_DATES: 1st input argument must be equal to or before the 2nd input argument!");
	}

	//check to see if date is within range
	if((date_difference(*this,start_date)>=0)&&(date_difference(end_date,*this)>=0)) {
		return(1);
	} else {
		return(0);
	}

}


//------------------------------------------------------------------------------------------------------
//---------------------------------GLOBAL FUNCTIONS-----------------------------------------------------
//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------
//IS_LEAP_YEAR	
//
//Test if date is a leap year or not
//
//INPUT:	-date
//
//OUTPUT:	-1 if date is a leap year
//			 0 if date is not a leap year
//------------------------------------------------------------------------------------------------------
bool is_leap_year(date mydate) {

	//is this a leap year?
	return((mydate.get_year()%4)==0);
}



//------------------------------------------------------------------------------------------------------
//IS_LEAP_YEAR	
//
//Test if date is a leap year or not
//
//INPUT:		-int = year to test
//
//OUTPUT:		-1 if year is a leap year
//				 0 if year is not a leap year
//------------------------------------------------------------------------------------------------------
bool is_leap_year(int year) {

	//is this a leap year?
	return(year%4==0);
}


//------------------------------------------------------------------------------------------------------
//DATE_DIFFERENCE	
//
//Obtain the number of days between two dates
//
//INPUT:	-date = first date
//			-date = second date
//
//OUTPUT:	-int =	number of days between two dates.  This is positive if the 1st date is
//					later than the 2nd date.
//------------------------------------------------------------------------------------------------------
int date_difference(date date1, date date2) {

	bool is_positive = 0;			//1 if date1 is later than date2, 0 otherwise
	date later_date, earlier_date;	//renamed later and earlier date
	bool exit_flag = 0;				//used when incrementing earlier date to later date
	int days_difference = 0;		//number of days between date1 and date 2

	if ((date1.get_year()==date2.get_year()) && (date1.get_month()==date2.get_month()) &&(date1.get_day()==date2.get_day())) {
		//Same date
		return(0);
	}

	//figure out if date1 is greater than date2
	if (date1.get_year() > date2.get_year()) {
		is_positive = 1;
	} else if ( (date1.get_year()==date2.get_year()) && (date1.get_month() > date2.get_month()) ) {
		is_positive = 1;
	} else if ( (date1.get_year()==date2.get_year()) && (date1.get_month()==date2.get_month()) && (date1.get_day() > date2.get_day()) ) {
		is_positive = 1;
	} else {
		is_positive = 0;
	}

	if (is_positive) {
		later_date = date1;
		earlier_date = date2;
	} else {
		later_date = date2;
		earlier_date = date1;
	}

	//increment earlier date until we get to later date
	while(exit_flag==0) {
		if(is_date_equal(earlier_date, later_date)) {
			exit_flag = 1;
		} else {
			earlier_date.increment_date_by_one();
			days_difference++;
		}
	}

	//do we need to switch the sign
	if (is_positive) {
	} else {
		days_difference = -days_difference;
	}

	return(days_difference);
}



//------------------------------------------------------------------------------------------------------
//IS_DATE_EQUAL	
//
//Test if two dates are equal
//
//INPUT:	-date = first date
//			-date = second date
//
//OUTPUT:	-1 if dates are equal
//			 0 if dates are not equal
//------------------------------------------------------------------------------------------------------
bool is_date_equal(date date1, date date2) {

	return( (date1.get_year()==date2.get_year()) && (date1.get_month()==date2.get_month()) && (date1.get_day()==date2.get_day()) );
}



//------------------------------------------------------------------------------------------------------
//DATE_TO_STRING	
//
//Returns a string representing the current date
//
//INPUT:	-const date&
//
//OUTPUT:	-string
//------------------------------------------------------------------------------------------------------
string date_to_string(const date& current_date) {

	stringstream ss;
	string month_string, day_string, year_string, date_string;

	//convert each int to a string
	ss << current_date.get_month();
	ss >> month_string;
	ss.clear();

	ss << current_date.get_day();
	ss >> day_string;
	ss.clear();

	ss << current_date.get_year();
	ss >> year_string;
	ss.clear();

	//build the date
	date_string = month_string + "/" + day_string + "/" + year_string;

	return(date_string);
}



//------------------------------------------------------------------------------------------------------
//IS_VALID_DATE	
//
//Checks if the date is valid
//
//INPUT:	-const date&
//
//OUTPUT:	-bool 1 if date is valid
//			      0 if date is not valid
//------------------------------------------------------------------------------------------------------
bool is_valid_date(const date& current_date) {

	int month_list[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool is_valid = 0;						//flag set to 1 if date is valid

	//check for leap years
	if (is_leap_year(current_date.get_year())) {
		month_list[1] = 29;
	}

	//make sure all month and day are positive (year can be negative to denote BC)
	if (current_date.get_month()<=0 || current_date.get_month()>12) {
		is_valid = 0;
	} else if (current_date.get_day()<=0 || current_date.get_day()>month_list[current_date.get_month() - 1]) {
		is_valid = 0;
	} else {
		//this is a valid date
		is_valid = 1;
	}

	return(is_valid);
}



