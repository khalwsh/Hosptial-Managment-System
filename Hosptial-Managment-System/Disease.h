
#ifndef HOSPTIAL_SYSTEM_DISEASE_H
#define HOSPTIAL_SYSTEM_DISEASE_H

#include<iostream>
#define line '\n'

class Disease{
private:
    //why disease class? cause every Patient will have a disease and every doctor has a disease or vector of disease that he is Specialize into
    char DiseaseName[25],VirusName[25];
    int NameLength,VirusLength;
    //array of char cause reading and writing
    //Disease Name and Virus Name
public:
    //take the details of certain disease
    void GetDiseaseDescription();
    void ShowDiseaseDetails()const;
    //printing the Details of Disease
    bool operator==(const Disease& b);
};

#endif //HOSPTIAL_SYSTEM_DISEASE_H
