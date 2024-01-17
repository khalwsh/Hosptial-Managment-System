

#ifndef HOSPTIAL_SYSTEM_PATIENT_H
#define HOSPTIAL_SYSTEM_PATIENT_H

#include "Person.h"
#include "Disease.h"
#include <iostream>
#include <utility>
class Patient: public Person{
private:

    int PatientId;
    //to distungised between Patients
    Disease PatientDisease;
    //every Patient has a Disease
    char AppointmentDate[25];
    char AppointmentDay[25];
    //the time that the Patient will see his doctor at
    const char PatientFile[25] = "patientData.dat";
    //storing the information of the patient
    const char PatientTempFile[25] = "patientData2.dat";
    //temporary data file

public:
    void GetPatientInformation();
    //taking Patient as input
    void AddPatient();
    //storing the Patient info into database
    void showPatientData()const;
    //Printing info about single patient
    void showPatientDataFromFile()const;
    //printing the whole database
    void DischargePatient();
    //delete patient from database
    void EditPatient();
    //Edit Patient status
    void DoPatientRelatedWork();
    //manage Patient Business
    std::pair<std::pair<Disease,char*>,char*> TakeIdReturnDiseaseOfThePatientAndPatientAppointmentDateAndPatientAppointmentDay();
    //first.first is the Disease
    //first.second is the Date
    //second is the Day
};

#endif //HOSPTIAL_SYSTEM_PATIENT_H
