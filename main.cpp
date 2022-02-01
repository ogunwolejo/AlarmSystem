/** creating an alarm system, that behaves like a regular alarm system, in which you set a time and at that time the it alarms the user
 *  if possible we will try to use get the audio of the system available
 *  then we will pick a song or randomly select one from a specified music directory
 *  i will be using a procedural(function) structure of coding
 * **/


#include <iostream>
#include <string>
#include <algorithm>

#include "headers/utility.h"

int main() {
    std::tm* local_Time {get_local_time()};
    std::cout << local_Time->tm_mday << " " << local_Time->tm_year << std::endl;

    std::string Calender_Time {get_time_in_calender_format()};
    std::cout << Calender_Time << std::endl;

    // select the days of the week you will want the alarm to work
    std::string INSTRUCTION_USERS {"Select the days you want the alarm to work, ensure give a space and then to add a fullstop(.) at the end of the days selected."};
    std::for_each(INSTRUCTION_USERS.begin(), INSTRUCTION_USERS.end(), [](char& c) {
        c = std::toupper(c);
    });

    std::cout << INSTRUCTION_USERS << std::endl;
    std::string get_days_for_alarm_to_work {};
    std::getline(std::cin, get_days_for_alarm_to_work, '.');

    std::vector<std::string> user_selected_days_for_alarm_to_work {split(get_days_for_alarm_to_work)};
    std::vector<std::string>* p_user_day_selection {&user_selected_days_for_alarm_to_work};
    std::cout << p_user_day_selection->size() << std::endl;
    for(short i{0}; i < user_selected_days_for_alarm_to_work.size(); i++) {
        std::cout << p_user_day_selection->at(i) << std::endl;
    }

    set_alarm_time(user_selected_days_for_alarm_to_work, 6, 00);
    return 0;
}
