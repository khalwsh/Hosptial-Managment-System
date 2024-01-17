#ifndef HOSPTIAL_SYSTEM_PERSON_H
#define HOSPTIAL_SYSTEM_PERSON_H
#include <iostream>
#define line '\n'

class Person{
//this is the base class for the doctor and the patient cause each of them is a person
private:

    int age;//every person has an age;
    char name[25],address[25],email[25],PhoneNumber[25];//every person has name ,address,email and PhoneNumber
    //why array of chars not string? cause I want to store in file and read form this file so i need to know the sizeof the object before reading or writing
    //so if it was string the size will vary form object to another one,,,, this lead me to choosing char array
public:

    //class constructor
    //initializing member varialbes
    Person():name(""),age(0),address(""),email(""),PhoneNumber("00000000000"){}

    //function to set the data for a Person
    void GetPersonData();

    //showing Person data
    void ShowPersonData()const;//doesn't expect to change the content of class member data
};



//int main(){
//    Person TestingPersonClass;
//    TestingPersonClass.GetPersonData();
//    TestingPersonClass.ShowPersonData();
//}
#endif //HOSPTIAL_SYSTEM_PERSON_H
