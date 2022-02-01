#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <iostream>
#include <ctime>
#include <string>
#include <vector>


/** function to get the current local time of a region **/
std::tm* get_local_time();

/** function that returns the time in a calendar format*/
std::string get_time_in_calender_format();

// to resolve the time_t pointer
std::time_t resolve_time(std::time_t* time_pointer);

// select time for alarm
void set_alarm_time(std::vector<std::string> users_selected_days, short hour, short min);

/** a user defined function that checks the string and split it based on the  white space*/
std::vector<std::string> split(std::string input);

/**filter to compare the elements in an array with an incoming element*/
//bool filter_array(std::string new_element, std::vector<std::string> array);

#endif
