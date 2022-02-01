
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

/** Defining the variable and pointer of the time_t variable */
std::time_t t {};
std::time_t* t_pointer {&t};

time_t time();

std::time_t resolve_time(std::time_t* time_pointer) {
    return std::time(time_pointer);
};

std::tm* get_local_time() {
    resolve_time(t_pointer);
    // initializing the struct pointer
    struct tm* local_time {nullptr};
    local_time = std::localtime(t_pointer);
    return local_time;
}


std::string get_time_in_calender_format() {
    resolve_time(t_pointer);
    char calender_result [25] {};
    strcpy(calender_result, std::asctime(std::localtime(t_pointer)));
    std::string calender_value {calender_result};
    return calender_value;
}

void set_alarm_time(std::vector<std::string> users_selected_days, short hour, short min) {
    std::tm* local_time {get_local_time()};
    std::string time_indication {};
    const std::vector<std::string> weekdays {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    std::vector<std::string> approved_user_days_for_alarm {};

    // check the days in the week that the user selected
    for(short i{0}; i < weekdays.size(); i++) {
        for(short p{0}; p < users_selected_days.size(); p++) {
            if (weekdays.at(i) == users_selected_days.at(p) ) {
                approved_user_days_for_alarm.insert(approved_user_days_for_alarm.end(),  users_selected_days.at(p));
            }
        }
    }

    // set the alarm by capturing the hour and min indicated by the user


}




// the functions check if each element in the array is the same as the incoming element and returns true if an element in the array is the same as the incoming element
bool filter_array(std::string new_element, std::vector<std::string> array) {
    for(short i {0}; i < array.size(); i++) {
        if(array.at(i).compare(new_element) == 0) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> split(std::string input) {
    std::vector<std::string> user_day_selection {};
    std::string new_values {};

    /** the split functions checks for the whitespaces that separates each word and it pushes those word to the array above
     *  this is broken down into various steps
     * */
    for(short i {0}; i < input.size(); ++i) {

        if(input.at(i) == ' ') {
            // if there is nothing in the array we can insert the first word and erase the content in the new_values variable
            if(user_day_selection.size() == 0) {
                user_day_selection.insert(user_day_selection.end(), new_values);
                new_values.erase();
                continue;
            }
            // if there are(is) element(s) in the array we filter the array to make sure the content we want to insert is not a repetition
            if(user_day_selection.size() > 0) {
                if(filter_array(new_values, user_day_selection) != true) {
                    user_day_selection.insert(user_day_selection.end(), new_values);
                    new_values.erase();
                    continue;
                }
            };

        }

        new_values += input.at(i);
    }
    return user_day_selection;
};
