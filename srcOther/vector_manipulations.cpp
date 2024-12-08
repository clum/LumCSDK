//Functions required for manipulating vectors
//Version History:	06/21/06: Created
//					07/03/06: Added functions to write to files
//					07/22/06: Added add_two_vector_double_together function
//					07/23/06: Added where_is_date_in_vector and where_is_date_in_vector_int functions
//					09/08/06: Added sum_across_columns_matrix_double function
//					09/21/06: Added transpose_vector_double


//PERTINENT LIBRARIES
#include <stdexcept>				//domain_error
#include <vector>					//vector
#include <string>					//string
#include <iostream>					//cout, endl
#include <fstream>					//ofstream
#include <sstream>					//stringstream
#include <algorithm>				//find
#include "my_date.h"				//date class
#include "string_manipulations.h"	//int_to_string

//USING DECLARATIONS
using std::domain_error;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ofstream;
using std::stringstream;
using std::find;


//------------------------------------------------------------------------------------------------------
//---------------------------------GLOBAL FUNCTIONS-----------------------------------------------------
//------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------
//ARE_TWO_VECTOR_DOUBLE_EQUAL
//
//Check if two vector<double> objects are the same
//
//INPUT:		-const vector<double>&:	1st vector
//				-const vector<double>&:	2nd vector
//
//OUTPUT:		-bool
//
//SIDE EFFECTS: -none
//------------------------------------------------------------------------------------------------------
bool are_two_vector_double_equal(const vector<double>& first, const vector<double>& second) {

	bool IS_EQUAL = 1;

	//make sure they are the same size
	if (first.size() != second.size()) {
		IS_EQUAL = 0;
	} else {
		//they are the same length, make sure the elements match
		vector<double>::const_iterator second_it = second.begin();
		for(vector<double>::const_iterator first_it = first.begin(); first_it != first.end(); first_it++) {
			if(*first_it != *second_it) {
				IS_EQUAL = 0;
			}
			second_it++;
		}

	}

	return(IS_EQUAL);
}



//------------------------------------------------------------------------------------------------------
//ARE_TWO_VECTOR_STRING_EQUAL
//
//Check if two vector<string> objects are the same
//
//INPUT:		-const vector<string>&:	1st vector
//				-const vector<string>&:	2nd vector
//
//OUTPUT:		-bool
//
//SIDE EFFECTS: -none
//------------------------------------------------------------------------------------------------------
bool are_two_vector_string_equal(const vector<string>& first, const vector<string>& second) {

	bool IS_EQUAL = 1;

	//make sure they are the same length
	if (first.size() != second.size()) {
		IS_EQUAL = 0;

	} else {
		//they are the same length, make sure that the elements match
		vector<string>::const_iterator second_it = second.begin();
		for(vector<string>::const_iterator first_it = first.begin(); first_it != first.end(); first_it++) {
			if(*first_it != *second_it) {
				IS_EQUAL = 0;
			}
			second_it++;
		}

	}

	return(IS_EQUAL);
}



//------------------------------------------------------------------------------------------------------
//IS_VECTOR_VECTOR_DOUBLE_A_MATRIX
//
//Check if a vector<vector<double> > is a valid matrix
//
//INPUT:		-const vector<vector<double> >&:	
//
//OUTPUT:		-bool
//
//SIDE EFFECTS: -none
//------------------------------------------------------------------------------------------------------
bool is_vector_vector_double_a_matrix(const vector<vector<double> >& s) {

	bool IS_VALID = 1;

	if (!s.empty()) {

		vector<double> current_row = s[0];
		size_t num_columns = current_row.size();

		for(vector<vector<double> >::const_iterator row_it = s.begin(); row_it != s.end(); row_it++) {
			if (row_it->size() != num_columns) {
				IS_VALID = 0;
			}
		}

	} else {
		//matrix is empty
		IS_VALID = 0;
	}

	return(IS_VALID);
}



//------------------------------------------------------------------------------------------------------
//WRITE_VECTOR_VECTOR_DOUBLE_TO_FILE
//
//Writes a vector<vector<double> > to a file.  Each element of the object is a row.  Rows are seperated
//by a new line \n.  Each element in a column is seperated by a tab.
//
//INPUT:		-const vector<vector<double> >&:	item to write to file
//				-string:							directory and file name string
//
//OUTPUT:		-bool
//
//SIDE EFFECTS: -none
//------------------------------------------------------------------------------------------------------
bool write_vector_vector_double_to_file(const vector<vector<double> >& s, string directory_file_string) {

	ofstream ofs(directory_file_string.c_str());		//file stream to output file
	stringstream ss;									//convert double to string
	vector<double> current_row;							//current row
	string current_value;								//current value converted to string

	for(vector<vector<double> >::const_iterator row_it = s.begin(); row_it != s.end(); row_it++) {
		//what is the current row
		current_row = *row_it;

		for(vector<double>::const_iterator col_it = current_row.begin(); col_it != current_row.end(); col_it++) {
			ss << *col_it;
			ss >> current_value;
			ss.clear();

			current_value = current_value + '\t';
			ofs << current_value;
		}

		//write a newline
		ofs << '\n';
	}

	return(0);
}



//------------------------------------------------------------------------------------------------------
//WRITE_VECTOR_STRING_TO_FILE
//
//Writes a vector<string> to a file.  Each element of the object is a row.  Rows are seperated
//by a new line \n.
//
//INPUT:		-const vector<string>&:		item to write to file
//				-string:					directory and file name string
//
//OUTPUT:		-bool
//
//SIDE EFFECTS: -none
//------------------------------------------------------------------------------------------------------
bool write_vector_string_to_file(const vector<string>& vec, string directory_file_string) {

	ofstream ofs(directory_file_string.c_str());		//file stream to output file

	for(vector<string>::const_iterator row_it = vec.begin(); row_it != vec.end(); row_it++) {
		ofs << *row_it + '\n';
	}
	
	return(0);
}



//------------------------------------------------------------------------------------------------------
//WRITE_VECTOR_DOUBLE_TO_FILE
//
//Writes a vector<double> to a file.  Each element of the object is a row.  Rows are seperated
//by a new line \n.
//
//INPUT:		-const vector<double>&:		item to write to file
//				-string:					directory and file name string
//
//OUTPUT:		-bool
//
//SIDE EFFECTS: -none
//------------------------------------------------------------------------------------------------------
bool write_vector_double_to_file(const vector<double>& vec, string directory_file_string) {

	ofstream ofs(directory_file_string.c_str());		//file stream to output file

	for(vector<double>::const_iterator row_it = vec.begin(); row_it != vec.end(); row_it++) {
		ofs << *row_it;
		ofs << '\n';
	}
	
	return(0);
}



//------------------------------------------------------------------------------------------------------
//WRITE_VECTOR_DATE_TO_FILE
//
//Writes a vector<date> to a file.  Each element of the object is a row.  Rows are seperated
//by a new line \n.
//
//INPUT:		-const vector<date>&:		item to write to file
//				-string:					directory and file name string
//
//OUTPUT:		-bool
//
//SIDE EFFECTS: -none
//------------------------------------------------------------------------------------------------------
bool write_vector_date_to_file(const vector<date>& vec, string directory_file_string) {

	ofstream ofs(directory_file_string.c_str());		//file stream to output file

	for(vector<date>::const_iterator row_it = vec.begin(); row_it != vec.end(); row_it++) {
		ofs << date_to_string(*row_it);
		ofs << '\n';
	}
	
	return(0);
}


//------------------------------------------------------------------------------------------------------
//SUM_VECTOR_DOUBLE
//
//Sums up a vector<double>
//
//INPUT:		-const vector<double>&:		vector to sum
//
//OUTPUT:		-double:					sum of vector
//
//SIDE EFFECTS: -throws a domain error
//------------------------------------------------------------------------------------------------------
double sum_vector_double(const vector<double>& vec) {
	
	double sum = 0;

	if (vec.empty()) {
		throw domain_error("SUM_VECTOR_DOUBLE: Input vector to be summed is empty!");
	}

	for(vector<double>::const_iterator i = vec.begin(); i != vec.end(); i++) {
		sum = sum + *i;
	}

	return(sum);
}



//------------------------------------------------------------------------------------------------------
//ADD_TWO_VECTOR_DOUBLE_TOGETHER
//
//Adds up two vector<double> objects by adding the two element-wise.  The two vectors must be the same
//length and the return vector is the same length.
//
//INPUT:		-const vector<double>&:		1st vector to sum
//				-const vector<double>&:		2nd vector to sum
//
//OUTPUT:		-vector<double>:			The element wise sum of the two vectors
//
//SIDE EFFECTS: -throws a domain error
//------------------------------------------------------------------------------------------------------
vector<double> add_two_vector_double_together(const vector<double>& first, const vector<double>& second) {
	
	vector<double>					ret;				//the sum of the two vectors
	vector<double>::const_iterator	first_it;			//points to the element of the first vector
	vector<double>::const_iterator	second_it;			//points to the element of the second  vector
	string							error_string;		//error string

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//make sure the vectors are the same length
	if(first.size() != second.size()) {
		error_string = "ADD_TWO_VECTOR_DOUBLE_TOGETHER: The vectors are not the same length!";
		throw domain_error(error_string);
	}


	
	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	second_it = second.begin();
	for(first_it = first.begin(); first_it != first.end(); first_it++) {
		ret.push_back(*first_it + *second_it);
		second_it++;
	}

	return(ret);
}



//------------------------------------------------------------------------------------------------------
//WHERE_IS_DATE_IN_VECTOR
//
//Returns an iterator which points to the element of the vector<date> where the date falls.  The iterator
//corresponds to the first element which is just before the desired date.
//
//For example, if the vector and date are, respectively
//
//	vector<date>	<=>	1/13/04, 2/15/04, 3/20/05
//	date			<=>	3/24/04
//
//then the iterator would point to the second element corresponding to 2/15/04.
//
//The vector<date> must be in chronological order.  The desired date must be after the first element of the
//vector<date>.  The returned iterator points to the element of the input argument vector and can be used
//to modify the original vector<date> object.
//
//
//INPUT:	-vector<date>&:				chronologically order vector of dates (linked to the original object)
//			-date:						desired date
//
//OUTPUT:	-vector<date>::iterator:	points to the first element in the vector which is before
//										the desired date but the next one is after the desired date
//
//SIDE-EFFECTS:	-throws a domain_error if error encountered
//------------------------------------------------------------------------------------------------------
vector<date>::iterator where_is_date_in_vector(vector<date>& dates, date desired_date) {

	vector<date>::iterator	next_date_it;						//used to point to the next date in the dates vector
	vector<date>::iterator	last_date_it;						//used to point to the last element of the dates vector;
	string					error_string;						//error string

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//Make sure vector is not emtpy
	if(dates.size()==0) {
		error_string = "WHERE_IS_DATE_IN_VECTOR: vector<date> is empty!";
		throw domain_error(error_string);
	}

	//Make sure the dates vector is in chronological order starting with the earliest date
	next_date_it = dates.begin();
	next_date_it++;

	last_date_it = dates.end();
	last_date_it--;
	for(vector<date>::iterator date_it = dates.begin(); date_it != last_date_it; date_it++) {

		
		if(date_difference(*next_date_it,*date_it)<0) {
			error_string = "WHERE_IS_DATE_IN_VECTOR: dates vector is not in chronological order!";
			throw domain_error(error_string);
		}
		next_date_it++;		
	}

	//Make sure desired date is valid
	if(!desired_date.is_valid_date()) {
		error_string = "WHERE_IS_DATE_IN_VECTOR: desired_date is not a valid date!";
		throw domain_error(error_string);
	}

	//Make sure the desired date is not before the first element of the vector
	if(date_difference(desired_date, dates[0])<0) {
		error_string = "WHERE_IS_DATE_IN_VECTOR: desired_date is before the first element of the vector<date>!";
		throw domain_error(error_string);
	}




	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	//if the vector<date> object is only 1 object, simply return the iterator pointing to first element
	//(error checking above ensures that desired_dates comes on or after this first element date).
	if(dates.size()==1) {
        return(dates.begin());
	}

	//progress through the vector until we find the one where the next date is after the desired_date
	//but the current date is before or equal to the desired_date
	next_date_it = dates.begin();
	next_date_it++;

	last_date_it = dates.end();
	last_date_it--;
	for(vector<date>::iterator date_it = dates.begin(); date_it != last_date_it; date_it++) {

		//check if the
		if((date_difference(*next_date_it,desired_date)>0)&&(date_difference(desired_date,*date_it)>=0)) {
			return(date_it);
		}

		next_date_it++;		
	}

	//we made it through the entire loop and didn't find it, so it is the last element
	return(last_date_it);

}




//------------------------------------------------------------------------------------------------------
//WHERE_IS_DATE_IN_VECTOR_INT
//
//Returns an integer which corresponds to the element index (with 0 corresponding to the first element).
//
//For example, if the vector and date are, respectively
//
//	vector<date>	<=>	1/13/04, 2/15/04, 3/20/05
//	date			<=>	3/24/04
//
//then the returned integer would be 1.
//
//For more information, see where_is_date_in_vector
//
//
//INPUT:	-vector<date>&:				chronologically order vector of dates (linked to the original object)
//			-date:						desired date
//
//OUTPUT:	-int:						element index
//------------------------------------------------------------------------------------------------------
int	where_is_date_in_vector_int(vector<date>& dates, date desired_date) {

	vector<date>::iterator	element_it;		//iterator pointing to desired element
	int						element_index;	//index number

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//where_is_date_in_vector will check the data format


	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	element_it = where_is_date_in_vector(dates, desired_date);

	element_index = 0;
	for(vector<date>::iterator it = dates.begin(); it != dates.end(); it++) {
		if(it == element_it) {
			return(element_index);
		} else {
			element_index++;
		}
	}

	return(element_index);
}



//------------------------------------------------------------------------------------------------------
//WHERE_IS_STRING_IN_VECTOR
//
//Returns an iterator which points to the element of the vector<string> which equals the desired string.
//
//
//INPUT:		-vector<string>&:			vector of string
//				-string:					desired string
//
//OUTPUT:		-vector<string>::iterator:	points to the element in the vector which equals the desired string
//
//SIDE-EFFECTS:	-throws a domain_error if error encountered
//------------------------------------------------------------------------------------------------------
vector<string>::iterator where_is_string_in_vector(vector<string>& vector_string, string desired_string) {

	vector<string>::iterator	ret;				//returned iterator
	string						error_string;		//error string

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//Make sure vector is not emtpy
	if(vector_string.size()==0) {
		error_string = "WHERE_IS_STRING_IN_VECTOR: vector<string> is empty!";
		throw domain_error(error_string);
	}




	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	ret = find(vector_string.begin(), vector_string.end(), desired_string);

	if(ret==vector_string.end()) {

		error_string = "WHERE_IS_STRING_IN_VECTOR: desired string is not in vector<string>!\n";
		error_string = error_string + "Offending desired string is :" + desired_string + "\n";
		throw domain_error(error_string);

	} else {

		return(ret);

	}

}



//------------------------------------------------------------------------------------------------------
//WHERE_IS_STRING_IN_VECTOR_INT
//
//Returns an integer which corresponds to the element index (with 0 corresponding to the first element).
//
//For example, if the vector and desired string are, respectively
//
//	vector<string>	<=>	"cow", "dog", "pig"
//	date			<=>	"cow"
//
//then the returned integer would be 0.
//
//For more information, see where_is_string_in_vector
//
//
//INPUT:	-vector<string>&:	vector of strings (linked to the original object)
//			-string:			desired string
//
//OUTPUT:	-int:				element index
//------------------------------------------------------------------------------------------------------
int	where_is_string_in_vector_int(vector<string>& vector_string, string desired_string) {

	vector<string>::iterator	element_it;		//iterator pointing to desired element
	int							element_index;	//index number

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//where_is_string_in_vector will check the data format


	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	element_it = where_is_string_in_vector(vector_string, desired_string);

	element_index = 0;
	for(vector<string>::iterator it = vector_string.begin(); it != vector_string.end(); it++) {
		if(it == element_it) {
			return(element_index);
		} else {
			element_index++;
		}
	}

	return(element_index);
}












//----------------------------MATRIX FUNCTIONS-------------------------------

//------------------------------------------------------------------------------------------------------
//DISPLAY_MATRIX_DOUBLE
//
//Displays the matrix to the standard output.
//
//
//INPUT:		-const vector<vector<double> >&:	Matrix to display
//
//OUTPUT:		-void
//------------------------------------------------------------------------------------------------------
void display_matrix_double(const vector<vector<double> >& matrix) {

	for(vector<vector<double> >::const_iterator row_it = matrix.begin(); row_it != matrix.end(); row_it++) {
		
		for(vector<double>::const_iterator col_it = row_it->begin(); col_it != row_it->end(); col_it++) {
			cout << *col_it << " ";
		}
		cout << endl;
	}

}



//------------------------------------------------------------------------------------------------------
//ZERO_MATRIX_DOUBLE
//
//Creates an MxN matrix of zeros.
//
//
//INPUT:		-int:						M (number of row)
//				-int:						N (number of columns)
//
//OUTPUT:		-vector<vector<double> >:	MxN matrix of zeros
//
//SIDE-EFFECTS:	-throws a domain_error
//------------------------------------------------------------------------------------------------------
vector<vector<double> >	zero_matrix_double(int M, int N) {

	vector<vector<double> >	ret;
	vector<double>			row;
	string					error_string;

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//Make sure M and N are positive
	if((M<=0)||(N<=0)) {
		error_string = "ZERO_MATRIX_DOUBLE: Both M and N must be positive!";
		throw domain_error(error_string);
	}


	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	for(int n = 0; n != N; n++) {
		row.push_back(0);
	}

	for(int m = 0; m != M; m++) {
		ret.push_back(row);
	}

	return(ret);

}



//------------------------------------------------------------------------------------------------------
//GET_NUMBER_ROWS_MATRIX_DOUBLE
//
//Get the number of rows in a matrix of doubles.
//
//
//INPUT:		-const vector<vector<double> >&:	Matrix of doubles
//
//OUTPUT:		-int:								Number of rows
//------------------------------------------------------------------------------------------------------
int	get_number_rows_matrix_double(const vector<vector<double> >& matrix) {

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//none

	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	return((int)matrix.size());
}



//------------------------------------------------------------------------------------------------------
//GET_NUMBER_ROWS_MATRIX_DOUBLE
//
//Get the number of columns in a matrix of doubles.
//
//
//INPUT:		-const vector<vector<double> >&:	Matrix of doubles
//
//OUTPUT:		-int:								Number of columns
//------------------------------------------------------------------------------------------------------
int get_number_columns_matrix_double(const vector<vector<double> >& matrix) {
	
	vector<vector<double> >::const_iterator row_it;

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//none

	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	return((int)(matrix.begin()->size()));

}



//------------------------------------------------------------------------------------------------------
//MATRIX_DOUBLE_ELEMENT_REPLACE
//
//Replaces the element of a matrix with the desired value.  Note that the indexing starts with 0
//(ie the top right element of the matrix is the 0,0 element).
//
//
//INPUT:		-vector<vector<double> >&:	Matrix to have element replaced
//				-int:						row number
//				-int:						col number
//				-double:					value to insert into [row;col]
//
//OUTPUT:		-void
//
//SIDE-EFFECTS:	-throws a domain_error
//------------------------------------------------------------------------------------------------------
void matrix_double_element_replace(std::vector<std::vector<double> >& matrix, int row, int col, double value) {

	vector<vector<double> >::iterator	row_it;
	vector<double>::iterator			col_it;
	string								error_string;

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//Make sure row and col are non-negative
	if((row<0)||(col<0)) {
		error_string = "MATRIX_DOUBLE_ELEMENT_REPLACE: both row and col must be non-negative (equal to zero is ok)";
		throw domain_error(error_string);
	}

	//Make sure row and col do not exceed matrix dimensions
	if(row+1 > get_number_rows_matrix_double(matrix)) {
		error_string = "MATRIX_DOUBLE_ELEMENT_REPLACE: row exceeds matrix dimensions\n";
		error_string = error_string + "matrix has dimensions " + int_to_string(get_number_rows_matrix_double(matrix)) + "x" + int_to_string(get_number_columns_matrix_double(matrix)) + "\n";
		error_string = error_string + "row index of " + int_to_string(row) + " (which is really the " + int_to_string(row+1) + "th row) exceeds dimensions.";
		throw domain_error(error_string);
	}

	if(col+1 > get_number_columns_matrix_double(matrix)) {
		error_string = "MATRIX_DOUBLE_ELEMENT_REPLACE: col exceeds matrix dimensions\n";
		error_string = error_string + "matrix has dimensions " + int_to_string(get_number_rows_matrix_double(matrix)) + "x" + int_to_string(get_number_columns_matrix_double(matrix)) + "\n";
		error_string = error_string + "col index of " + int_to_string(col) + " (which is really the " + int_to_string(col+1) + "th row) exceeds dimensions.";
		throw domain_error(error_string);
	}
		


	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	row_it = matrix.begin();
	for(int m = 0; m != row; m++) {
		row_it++;
	}

	col_it = row_it->begin();
	for(int n = 0; n != col; n++) {
		col_it++;
	}

	//replace the value
	*col_it = value;

}



//------------------------------------------------------------------------------------------------------
//SUM_TWO_MATRIX_DOUBLE
//
//Adds two matrices together element-wise.
//
//
//INPUT:		-const vector<vector<double> >&:	1st matrix
//				-const vector<vector<double> >&:	2nd matrix
//
//OUTPUT:		-vector<vector<double> >:			sum of the two matrices.
//
//SIDE-EFFECTS:	-throws a domain_error
//------------------------------------------------------------------------------------------------------
vector<vector<double> >	sum_two_matrix_double(const vector<vector<double> >& first, const vector<vector<double> >& second) {

	vector<vector<double> >	ret;					//returned matrix sum
	string					error_string;			//error string
	int						M, N;					//matrix dimensions
	int						row_index, col_index;	//indices
	vector<double>			current_row_1;			//current row of matrix 1
	vector<double>			current_row_2;			//current row of matrix 2
	vector<double>			current_row_sum;		//current sum of the rows

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//Make sure matrix dimensions match
	if(get_number_rows_matrix_double(first) != get_number_rows_matrix_double(second)) {
		error_string = "SUM_TWO_MATRIX_DOUBLE: Number of rows in both matrices must be the same!";
		throw domain_error(error_string);
	}

	if(get_number_columns_matrix_double(first) != get_number_columns_matrix_double(second)) {
		error_string = "SUM_TWO_MATRIX_DOUBLE: Number of columns in both matrices must be the same!";
		throw domain_error(error_string);
	}


	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	M = get_number_rows_matrix_double(first);
	N = get_number_columns_matrix_double(first);

	for(row_index = 0; row_index != M; row_index++) {

		//get the current row
		current_row_1 = first[row_index];
		current_row_2 = second[row_index];

		for(col_index = 0; col_index != N; col_index++) {
			//get the current columns
			current_row_sum.push_back(current_row_1[col_index] + current_row_2[col_index]);
		}

		ret.push_back(current_row_sum);
		current_row_sum.clear();
	}

	return(ret);

}



//------------------------------------------------------------------------------------------------------
//SUM_ACROSS_COLUMNS_MATRIX_DOUBLE
//
//Takes an MxN matrix and sums across the columns to result in a Mx1 vector which is the sum across the
//columns (as the row remains constant)
//
//
//INPUT:		-const vector<vector<double> >&:	matrix
//
//OUTPUT:		-vector<double>:					sum across the columns
//
//SIDE-EFFECTS:	-throws a domain_error
//------------------------------------------------------------------------------------------------------
vector<double>	sum_across_columns_matrix_double(const vector<vector<double> >& matrix) {

	vector<double> sum_across_columns;		//vector of size Mx1

	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//make sure matrix is not empty
	if(get_number_rows_matrix_double(matrix)==0 || get_number_columns_matrix_double(matrix)==0) {
		throw domain_error("SUM_ACROSS_COLUMNS_MATRIX_DOUBLE: Cannot sum because one of the dimensions of the matrix is zero!");
	}

	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	for(vector<vector<double> >::const_iterator row_it = matrix.begin(); row_it != matrix.end(); row_it++) {
		sum_across_columns.push_back(sum_vector_double(*row_it));
	}

	return(sum_across_columns);

}



//------------------------------------------------------------------------------------------------------
//TRANSPOSE_MATRIX_DOUBLE
//
//Transpose a matrix
//
//
//INPUT:		-const vector<vector<double> >&:	matrix
//
//OUTPUT:		-vector<vector<double> >:			transpose of input matrix
//
//SIDE-EFFECTS:	-throws a domain_error
//------------------------------------------------------------------------------------------------------
vector<vector<double> >	transpose_matrix_double(const vector<vector<double> >& A) {

	vector<vector<double> > AT;					//matrix tranpose
	vector<double>			current_row;		//current row
	vector<double>			temp_row;			//the row of the transposed matrix
	int						M;					//number of rows
	int						N;					//number of columns


	//---------------------------CHECKING DATA FORMAT------------------------------------------
	//make sure matrix is not empty
	M = get_number_rows_matrix_double(A);
	N = get_number_columns_matrix_double(A);

	if(M==0 || N==0) {
		throw domain_error("TRANSPOSE_MATRIX_DOUBLE: Cannot transpose because one of the dimensions of the matrix is zero!");
	}

	//----------------------------BEGIN CALCULATIONS-------------------------------------------
	for(int n = 0; n < N; n++) {
		//n now is set to the desired column, run down each row at the current column and create a vector

		for(vector<vector<double> >::const_iterator row_it = A.begin(); row_it != A.end(); row_it++) {
			current_row = *row_it;
			temp_row.push_back(current_row[n]);
		}

		AT.push_back(temp_row);
		temp_row.clear();

	}

	return(AT);
	

}

