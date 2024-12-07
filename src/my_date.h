#ifndef GUARD_my_date_h
#define GUARD_my_date_h

//PERTINENT LIBRARIES
#include <string>			//string
#include <vector>			//vector

class date {
public:
	//Interface goes here
	date();											//construct an empty date object

	void			parse_date(const std::string);				//reads in string and converts to this data type
	void			parse_date(const std::string, const int);	//same as above but for cases where year is YY and allows you to specify century
	int				get_month() const {return(month);}			//(accessor function which allows us to show month)
	int				get_day() const {return(day);}				//(accessor function which allows us to show day)
	int				get_year() const {return(year);}			//(accessor function which allows us to show year)
	void			increment_date_by_one();					//increments the date by one
	void			decrement_date_by_one();					//decrements the date by one
	void			increment_to_first_day_of_next_month();		//increment date to the first day of the next month
	void			set_day_to_first_of_month();				//set the date to the first of the month
	bool			is_valid_date();							//determines if this is a real date or not
	std::string		date_to_string() const;						//converts date to string
	bool			is_same_month_and_year(date);				//checks if the object has the same month and year as the input date
	bool			is_next_month_and_year(date);				//checks if the object has the next month as the input date
	bool			is_between_dates(date, date);				//check to see if the date is between two dates


private:
	//Implementation goes here
	int month;
	int day;
	int year;
};



//FUNCTION PROTOTYPES
bool						is_leap_year(date);										//check if the date is in a leap year
bool						is_leap_year(int);										//check if the year is a leap year
int							date_difference(date, date);							//number of days between dates
bool						is_date_equal(date, date);								//are the two dates the same
std::string					date_to_string(const date&);							//convert date to string
bool						is_valid_date(const date&);								//determines if this a real date or not


#endif