#include "Disease.h"
#include <iostream>

void Disease::GetDiseaseDescription(){
    std::string dis;
    std::cout<<"Enter name of the disease: ";
    std::cin>>dis;
    NameLength=(int)dis.size();
    for(int i=0;i<NameLength;i++){
        DiseaseName[i]=dis[i];
    }
    std::cout<<"Enter the name of the Virus: ";
    std::cin>>dis;
    VirusLength=(int)dis.size();
    for(int i=0;i<NameLength;i++){
        VirusName[i]=dis[i];
    }
}

void Disease::ShowDiseaseDetails()const{
    std::cout<<"--------- Disease: ";
    for(int i=0;i<NameLength;i++)
        std::cout<<DiseaseName[i];
    std::cout<<" "<<"---------"<<line;
    std::cout<<"--------- Virus: ";
    for(int i=0;i<VirusLength;i++)
        std::cout<<VirusName[i];
    std::cout<<" "<<"---------"<<line;
}
bool Disease::operator==(const Disease &b) {
    for(int i=0;i<NameLength;i++) {
        if ((std::isalpha(DiseaseName[i])||std::isalpha(b.DiseaseName[i]))&&DiseaseName[i] != b.DiseaseName[i])return false;
    }
    for(int i=0;i<VirusLength;i++){
        if ((std::isalpha(VirusName[i])||std::isalpha(b.VirusName[i]))&&VirusName[i] != b.VirusName[i])return false;
    }
    return true;
}