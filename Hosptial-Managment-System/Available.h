
#ifndef HOSPTIAL_SYSTEM_AVAILABLE_H
#define HOSPTIAL_SYSTEM_AVAILABLE_H
#include <iostream>
#include <ctime>
//#include "Doctor.h"
#define line '\n'
class Available{

private:
    char ShiftStart[25],ShiftEnd[25];
    //the starting of the 2Shifts of the doctor [MorningShift,EveningShift]
    bool DayOfWeek[7];
    //[which day of week that this doctor is available]
    int NumberOfWorkingDaysInWeek;
    //[how many day he is Available on]
    friend class Doctor;
public:
    Available():ShiftStart("00:00:00"),ShiftEnd("00:00:00"),NumberOfWorkingDaysInWeek(0){
        for(auto &val:DayOfWeek)val=false;
    }
    void WhenAvailable();
    //managing Availablity of the Doctor
    int DayMapping(const std::string &s)const;
    //Function take the day and return which day of week this day is
    //Saturday-->0,.....
    void DisplayAvailability()const ;
    //print the member variables
    tm* GetCurrentTime()const;

    int ConvertHHMMSSToMinutes(const char arr[])const;
};

#endif //HOSPTIAL_SYSTEM_AVAILABLE_H
