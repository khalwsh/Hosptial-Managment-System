#include <iostream>
#include "Patient.h"
#include "Doctor.h"

int main() {
    Patient p;//make an Patient object as my key to Patients DataBase
    Doctor d;//make an Doctor object as my key to Doctors DataBase;
    int choice;//which option you want? patient or doctor
    do{

        std::cout<<"Enter option 1 for patient"<<line;
        std::cout<<"Enter option 2 for Doctor"<<line;
        std::cout<<"Enter option 3 for Arrange Appointment between Patient and Doctor";
        std::cin>>choice;

        if(choice==1){
            p.DoPatientRelatedWork();
        }else if(choice==2){
            d.DoDoctorRelatedWork();
        }else if(choice==3){
            std::pair<std::pair<Disease,char*>,char*>SickGuy = p.TakeIdReturnDiseaseOfThePatientAndPatientAppointmentDateAndPatientAppointmentDay();
            if(SickGuy.first.second==nullptr||SickGuy.second==nullptr){
                continue;
            }
            d.PrintingDoctorsThatCanTreatCertainPatient(SickGuy.first.first,SickGuy.first.second,SickGuy.second);
        }

    }while(choice>=1&&choice<=3);
}
