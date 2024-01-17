

#ifndef HOSPTIAL_SYSTEM_DOCTOR_H
#define HOSPTIAL_SYSTEM_DOCTOR_H

#include "Available.h"
#include "Disease.h"
#include "Person.h"

#include <iostream>
#include <fstream>
//Doctor class in child class from Person cause every Doctor is a person

class Doctor: public Person{
private:
    int DoctorId;
    //every has Id
    Disease DoctorSpecialization;
    //the Disease that the Doctor is Specialized into
    Available available;
    //times that the Doctor is in his shift
    char DoctorFile[20] = "doctorsData.dat";
    //local database for doctors
    char DoctorTempFile[20] = "DoctorsData2.dat";
    //temporary file help in Deleting doctors [store data at,exculde the deleted then return the data into database]
public:
    void GetDoctorData();
    void ShowDoctorData()const;
    void AddDoctor();
    void ShowDataFromFile()const;
    void DeleteDoctor();
    void EditDoctor();
    void DoDoctorRelatedWork();
    void PrintingDoctorsThatCanTreatCertainDisease(Disease& d)const;
    void PrintingDoctorsThatCanTreatCertainPatient(const Disease & d,char* AppointmentDate,char*AppointmentDay);
};

#endif //HOSPTIAL_SYSTEM_DOCTOR_H
