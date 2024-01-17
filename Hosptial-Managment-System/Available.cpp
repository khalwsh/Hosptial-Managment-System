#include "Available.h"
int Available::DayMapping(const std::string &day)const{
    std::string lowercaseDay = day;
    //handling if the input was uppercase
    std::transform(lowercaseDay.begin(), lowercaseDay.end(), lowercaseDay.begin(), ::tolower);

    // Array of days in a week
    std::string days[] = {"saturday","sunday", "monday", "tuesday", "wednesday", "thursday", "friday"};

    // Search for the day in the array
    int cnt=0;
    for(auto &val:days){
        if(day==val){
            return cnt;
        }
        cnt++;
    }
    return -1;
}
int Available::ConvertHHMMSSToMinutes(const char arr[]) const {
    return (arr[0]-'0')*10*3600+(arr[1]-'0')*3600+(arr[3]-'0')*10*60+(arr[4]-'0')*60+(arr[6]-'0')*10+(arr[7]-'0');
}
void Available::WhenAvailable(){
    do {

        std::cout << "Enter Number of Available days in week 1-7 :" << line;

        std::cin >> NumberOfWorkingDaysInWeek;
        //how many days per week that the doctor is working
        //assert(7>=NumberOfWorkingDaysInWeek>=1);
        if(NumberOfWorkingDaysInWeek<1||NumberOfWorkingDaysInWeek>7){

            //validation for the input
            std::cout<<"Error invalid Data "<<line;

            std::cout<<"Enter number between 1 - 7"<<line;

        }

    }while(NumberOfWorkingDaysInWeek<1||NumberOfWorkingDaysInWeek>7);

    std::cout<<"Enter "<<NumberOfWorkingDaysInWeek<<" "<<"days of week that you are Available at: ";

    for(int i=0;i<7;i++){
        if(DayOfWeek[i])DayOfWeek[i]=false;
    }

    for(int i=0;i<NumberOfWorkingDaysInWeek;i++){
        std::string day;
        std::cin>>day;

        for(auto &val:day){
            val=(char) tolower(val);//handling upper case and mixed words
        }

        int DayIndexOfWeek= DayMapping(day);
        if(DayIndexOfWeek==-1){
            //if DayIndexOfWeek is -1 then you entered wrong day so I handle that by repeat the question again and show you the writed list to choose from

            i--;//cause this input doesn't count cause it's wrong

            std::cout<<"[Error] The day you entered is wrong please make sure that you have to enter a day from this list"<<line;

            for(auto &val:{"saturday","sunday", "monday", "tuesday", "wednesday", "thursday", "friday"})
                std::cout<<val<<" ";

            std::cout<<line;

            continue;//don't continue executing cause you gonna face runtime error [negative index]
        }

        DayOfWeek[DayIndexOfWeek]=true;
    }

    std::cout<<"Enter Dr. First Shift Format HH:MM:SS: ";
    std::cin>>ShiftStart;

    std::cout<<"Enter Dr. Second Shift Format HH:MM:SS: ";
    std::cin>>ShiftEnd;

}
tm* Available::GetCurrentTime() const {
    time_t RawTime;
    struct tm * TimeInfo;
    time(&RawTime);
    TimeInfo = localtime(&RawTime);
    return TimeInfo;
}
void Available::DisplayAvailability()const {

    std::cout << std::asctime(GetCurrentTime()) << line;
    //printing the current time
    std::cout << "Dr. is available for " << NumberOfWorkingDaysInWeek << " days in week " << line;
    //presenting the days that the doctor is working at
    std::string week[]{"saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday"};

    for (int i = 0; i < 7; i++) {
        if (DayOfWeek[i]) {
            std::cout << week[i] << line;
        }
    }
    Error:
    std::cout << "Dr. StartingShift: " << ShiftStart << line;
    std::cout << "Dr. EndingShift: " << ShiftEnd << line;

    for (int i = 0; i < 8; i++) {
        if (i == 2 || i == 5) {
            if (ShiftEnd[i] != ':' || ShiftStart[i] != ':'){
                std::cout<<"Wrong Format The Correct Format is  HH:MM:SS"<<line;
                goto Error;
            }
        } else {
            if (!std::isdigit(ShiftStart[i]) || !std::isdigit(ShiftEnd[i])){
                std::cout<<"Wrong Format The Correct Format is  HH:MM:SS"<<line;
                goto Error;
            }
        }
    }
    if(ConvertHHMMSSToMinutes(ShiftEnd)< ConvertHHMMSSToMinutes(ShiftStart)){
        std::cout<<"invalid Shifts ShiftEnding Should be after ShiftStarting"<<line;
        goto Error;
    }
}