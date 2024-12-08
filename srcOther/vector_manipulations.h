#ifndef GUARD_vector_manipulations_h
#define GUARD_vector_manipulations_h

//PERTINENT LIBRARIES
#include <vector>			//vector
#include <string>			//string
#include "my_date.h"		//date

//FUNCTION PROTOTYPES
bool								are_two_vector_double_equal(const std::vector<double>&, const std::vector<double>&);
bool								are_two_vector_string_equal(const std::vector<std::string>&, const std::vector<std::string>&);
bool								is_vector_vector_double_a_matrix(const std::vector<std::vector<double> >&);
bool								write_vector_vector_double_to_file(const std::vector<std::vector<double> >&, std::string);
bool								write_vector_string_to_file(const std::vector<std::string>&, std::string);
bool								write_vector_double_to_file(const std::vector<double>&, std::string);
bool								write_vector_date_to_file(const std::vector<date>&, std::string);
double								sum_vector_double(const std::vector<double>&);
std::vector<double>					add_two_vector_double_together(const std::vector<double>&, const std::vector<double>&);
std::vector<date>::iterator			where_is_date_in_vector(std::vector<date>&, date);		//finds out where in a vector<date> the date falls
int									where_is_date_in_vector_int(std::vector<date>&, date);	//finds out where in a vector<date> the date falls
std::vector<std::string>::iterator	where_is_string_in_vector(std::vector<std::string>&, std::string);		//finds out where in a vector<date> the date falls
int									where_is_string_in_vector_int(std::vector<std::string>&, std::string);	//finds out where in a vector<date> the date falls


//matrix functions
void								display_matrix_double(const std::vector<std::vector<double> >&);
std::vector<std::vector<double> >	zero_matrix_double(int, int);				//creates a matrix of zeros
int									get_number_rows_matrix_double(const std::vector<std::vector<double> >&);
int									get_number_columns_matrix_double(const std::vector<std::vector<double> >&);
void								matrix_double_element_replace(std::vector<std::vector<double> >&, int, int, double);
std::vector<std::vector<double> >	sum_two_matrix_double(const std::vector<std::vector<double> >&, const std::vector<std::vector<double> >&);
std::vector<double>					sum_across_columns_matrix_double(const std::vector<std::vector<double> >&);
std::vector<std::vector<double> >	transpose_matrix_double(const std::vector<std::vector<double> >&);

#endif