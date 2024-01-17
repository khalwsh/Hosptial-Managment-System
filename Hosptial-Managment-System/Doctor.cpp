#include "Doctor.h"

void Doctor::GetDoctorData(){

    std::cout<<"Enter data of Doctor: "<<line;
    GetPersonData();

    std::cout<<"Enter doctor id: ";
    std::cin>>DoctorId;

    std::cout<<"Enter name of Doctor Specialization: ";
    DoctorSpecialization.GetDiseaseDescription();

    available.WhenAvailable();

}
void Doctor::ShowDoctorData() const {

    std::cout<<"Details of Doctors are:"<<line;
    ShowPersonData();

    std::cout<<"Doctor id is: "<<DoctorId<<line;
    DoctorSpecialization.ShowDiseaseDetails();
    available.DisplayAvailability();
    std::cout<<line;

}
void Doctor::AddDoctor() {

    GetDoctorData();
    std::ofstream DoctorDataBase(DoctorFile,std::ios::binary|std::ios::out|std::ios::app);

    DoctorDataBase.write((char*)this,sizeof (Doctor));//write into file

}
void Doctor::PrintingDoctorsThatCanTreatCertainDisease(Disease & c)const{
    std::cout<<"Doctors can Treat This Disease: ";
    c.ShowDiseaseDetails();
    std::ifstream ReadDataFromDataBase(DoctorFile,std::ios::binary|std::ios::in);
    while(!ReadDataFromDataBase.eof()){
        if(ReadDataFromDataBase.read((char*)this,sizeof(Doctor))&&this->DoctorSpecialization == c){
            ShowDoctorData();
        }
    }
}
void Doctor::ShowDataFromFile()const{

    std::cout<<"=============================================================="<<line;
    std::ifstream ReadDataFromDataBase(DoctorFile,std::ios::binary|std::ios::in);
    while(!ReadDataFromDataBase.eof()){
        if(ReadDataFromDataBase.read((char*)this,sizeof(Doctor))){
            ShowDoctorData();
        }
    }
    std::cout<<"=============================================================="<<line;

}
void Doctor::DeleteDoctor() {

    int IdToDelete;
    bool Flag=false;
    std::cout<<"Enter the Id of the doctor you want to delete: ";
    std::cin>>IdToDelete;
    std::ifstream IfDoctor;
    IfDoctor.open(DoctorFile,std::ios::binary|std::ios::in);
    std::ofstream OfDoctor(DoctorTempFile,std::ios::binary|std::ios::out);
    while(!IfDoctor.eof()){
        IfDoctor.read((char*)this,sizeof(Doctor));
        if(IfDoctor){
            if(IdToDelete==DoctorId){
                Flag=true;
            }else{
                OfDoctor.write((char*)this,sizeof(Doctor));
            }
        }
    }
    IfDoctor.close();
    OfDoctor.close();
    std::remove(DoctorFile);
    std::rename(DoctorTempFile,DoctorFile);
    if(Flag){
        std::cout<<"Record successfully deleted"<<line;
    }else{
        std::cout<<"Record not Found "<<line;
    }

}
void Doctor::EditDoctor() {

    int IdToEdit;
    bool Flag=false;
    int pos;
    std::cout<<"Enter Doctor Id to Edit: ";
    std::cin>>IdToEdit;
    std::fstream FDoctor;
    FDoctor.open(DoctorFile,std::ios::binary|std::ios::in|std::ios::out);
    while(!FDoctor.eof()){
        pos=(int)FDoctor.tellg();
        FDoctor.read((char*)this,sizeof(Doctor));
        if(FDoctor){

            if(DoctorId==IdToEdit){
                Flag=true;
                GetDoctorData();
                FDoctor.seekp(pos);
                FDoctor.write((char*)this,sizeof(Doctor));
                ShowDoctorData();
                break;
            }

        }
    }
    FDoctor.close();
    if(Flag){
        std::cout<<"Record successfully Edited"<<line;
    }else
        std::cout<<"Record not Found"<<line;

}
void Doctor::DoDoctorRelatedWork(){

    int choice;
    do{
        std::cout<<"Enter option 1 to add Doctor "<<line;
        std::cout<<"Enter option 2 to show all data "<<line;
        std::cout<<"Enter option 3 to discharge Doctor "<<line;
        std::cout<<"Enter option 4 to Edit Doctor "<<line;
        std::cout<<"Enter option 5 to Printing The doctors Can Treat a Certain Disease You choose"<<line;
        std::cout<<"Enter option 6 to Exit the Program "<<line;
        std::cin>>choice;

        if(choice==1){
            do{
                AddDoctor();
                AskingToAddAgain:
                std::cout<<"Add another Doctor? [yes or no] ";
                std::string ans;
                std::cin>>ans;
                for(auto &val:ans)val=(char) tolower(val);
                if(ans=="no")break;
                else if(ans!="yes"){
                    std::cout<<"[Error] Enter yes or no to continue"<<line;
                    goto AskingToAddAgain;
                }
            }while(true);
        }else if(choice==2){
            ShowDataFromFile();
        }else if(choice==3){
            DeleteDoctor();
        }else if(choice==4){
            EditDoctor();
        }else if(choice==5){
            Disease d;
            d.GetDiseaseDescription();
            PrintingDoctorsThatCanTreatCertainDisease(d);
        }else if(choice==6){
            break;
        }else{
            std::cout<<"[Error] you must Enter Integer in the following range[1,5]"<<line;
        }
    }while(true);

}
void Doctor::PrintingDoctorsThatCanTreatCertainPatient(const Disease & d,char* AppointmentDate,char*AppointmentDay){
    std::ifstream ReadDataFromDataBase(DoctorFile,std::ios::binary|std::ios::in);
    while(!ReadDataFromDataBase.eof()){
        if(ReadDataFromDataBase.read((char*)this,sizeof(Doctor))){
            int PatientDate=available.ConvertHHMMSSToMinutes(AppointmentDate);
            int SF=available.ConvertHHMMSSToMinutes(available.ShiftStart);
            int EF=available.ConvertHHMMSSToMinutes(available.ShiftEnd);
            if(DoctorSpecialization == d && SF <= PatientDate && EF >= PatientDate && available.DayOfWeek[available.DayMapping(AppointmentDay)] )
               ShowDoctorData();
        }
    }
}