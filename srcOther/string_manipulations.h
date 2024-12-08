#ifndef GUARD_string_manipulations_h
#define GUARD_string_manipulations_h

//PERTINENT LIBRARIES
#include <string>			//string
#include <vector>			//vector

//FUNCTION PROTOTYPES
void						string_to_char_array(std::string, char mychars[], size_t);
std::string					string_search_replace(const std::string&, const std::string&, const std::string&);
std::string::const_iterator string_find(const std::string&, const std::string&);
std::vector<std::string>	split_tab(const std::string&);
std::string					int_to_string(const int&);
bool						has_alnum(const std::string&);

#endif