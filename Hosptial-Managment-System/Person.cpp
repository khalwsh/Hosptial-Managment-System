
#include "Person.h"

void Person::GetPersonData(){

    std::cout<<"Enter your name: ";

    std::cin>>name;

    std::cout<<"Enter your address: ";

    std::cin>>address;

    std::cout<<"Enter your age: ";

    std::cin>>age;

    std::cout<<"Enter your phoneNumber: ";

    std::cin>>PhoneNumber;

    std::cout<<"Enter your Email: ";

    std::cin>>email;

}
void Person::ShowPersonData() const{

    std::cout<<"name: "<<name;
    std::cout<<line;

    std::cout<<"address: "<<address;
    std::cout<<line;

    std::cout<<"age: "<<age;
    std::cout<<line;

    std::cout<<"PhoneNumber: "<<PhoneNumber;
    std::cout<<line;

    std::cout<<"Email: "<<email;
    std::cout<<line;

}