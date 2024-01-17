#include "Patient.h"
#include <fstream>

void Patient::GetPatientInformation(){

    std::cout<<"Enter Person Data: "<<line;

    GetPersonData();
    std::cout<<"Enter Disease Details: "<<line;

    PatientDisease.GetDiseaseDescription();

    std::cout<<"Enter Appoint day: ";
    std::cin>>AppointmentDay;

    std::cout<<"Enter Appoint date: ";
    std::cin>>AppointmentDate;
}
void Patient::AddPatient() {

    std::cout<<"Patient ID: ";
    std::cin>>PatientId;
    GetPatientInformation();
    std::ofstream PatientDatabase(PatientFile,std::ios::binary|std::ios::out|std::ios::app);//open the file to write at
    //std::ios::binary: Indicates that the file should be opened in binary mode. In binary mode, the file is treated as a binary stream, and no automatic newline character conversions are performed.
    //std::ios::out: Indicates that the file should be opened for output. This flag is necessary when you want to write data to the file.
    //std::ios::app: Indicates that the output should be appended to the end of the file. If the file already exists, the new data will be added at the end.

    PatientDatabase.write((char*)this,sizeof (Patient));//write this object into the file

}
void Patient::showPatientData() const {

    std::cout<<"---Patient Data---"<<line;
    std::cout<<"Patient Id: "<<PatientId<<line;
    ShowPersonData();
    PatientDisease.ShowDiseaseDetails();
    std::cout<<"Appointment Date: "<<AppointmentDate<<line;

}
void Patient::showPatientDataFromFile()const {

    std::cout << "==============================================================" << line;
    std::ifstream ReadDataFromDataBase(PatientFile, std::ios::binary | std::ios::in);

    if (!ReadDataFromDataBase.is_open()) {
        std::cerr << "Error opening file: " << PatientFile << line;
        return;
    }

    while (ReadDataFromDataBase.read((char *) this, sizeof(Patient))) {
        showPatientData();
    }

    ReadDataFromDataBase.close(); // Close the file after reading
    std::cout << "==============================================================" << line;

}
void Patient::DischargePatient(){

    int IdToDelete;
    bool flag = false;
    std::cout<<"Enter the Id of the Patient you want to Delete: ";
    std::cin>>IdToDelete;

    std::ifstream IfPatient;
    IfPatient.open(PatientFile,std::ios::in|std::ios::binary);

    std::ofstream ofPatient;
    ofPatient.open(PatientTempFile,std::ios::out| std::ios::binary);

    while(!IfPatient.eof()){

        IfPatient.read((char*)this,sizeof(Patient));
        if(IfPatient){
            if(IdToDelete==PatientId){
                flag=true;
            }else{
                ofPatient.write((char*)this,sizeof(Patient));
            }
        }

    }

    IfPatient.close();
    ofPatient.close();
    std::remove(PatientFile);
    std::rename(PatientTempFile,PatientFile);
    if(flag){
        std::cout<<"Record successfully Deleted "<<line;
    }else{
        std::cout<<"Record not Found "<<line;
    }

}

void Patient::EditPatient(){

    int IdToEdit,pos;
    bool flag=false;
    std::cout<<"Enter the Id of the patient you want to edit"<<line;
    std::cin>>IdToEdit;
    std::fstream fPatient;//read and write
    fPatient.open(PatientFile,std::ios::binary|std::ios::in|std::ios::out);
    while(!fPatient.eof()){
        pos=(int)fPatient.tellg();
        fPatient.read((char*)this,sizeof(Patient));
        if(fPatient) {
            if (IdToEdit == PatientId) {
                flag = true;
                GetPatientInformation();
                fPatient.seekp(pos);
                fPatient.write((char *) this, sizeof(Patient));
                showPatientData();
                break;
            }
        }
    }
    fPatient.close();

    if(flag){
        std::cout<<"Record successfully Edited "<<line;
    }else{
        std::cout<<"Record not Found "<<line;
    }

}
void Patient::DoPatientRelatedWork(){

    int choice;
    do{
        std::cout<<"Enter option 1 to add Patient "<<line;
        std::cout<<"Enter option 2 to show all data "<<line;
        std::cout<<"Enter option 3 to discharge Patient "<<line;
        std::cout<<"Enter option 4 to Edit Patient "<<line;
        std::cout<<"Enter option 5 to Exit the Program "<<line;
        std::cin>>choice;

        if(choice==1){
            do{
                AddPatient();
                AskingToAddAgain:
                std::cout<<"Add another Patient? [yes or no] ";
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
            showPatientDataFromFile();
        }else if(choice==3){
            DischargePatient();
        }else if(choice==4){
            EditPatient();
        }else if(choice==5){
            break;
        }else{
            std::cout<<"[Error] you must Enter Integer in the following range[1,5]"<<line;
        }
    }while(true);

}
std::pair<std::pair<Disease,char*>,char*>  Patient::TakeIdReturnDiseaseOfThePatientAndPatientAppointmentDateAndPatientAppointmentDay(){
    //return std::make_pair(std::make_pair(Disease(),nullptr),(nullptr));
    std::string filePath = PatientFile;

    // Create an ifstream object to check the existence of the file
    std::ifstream fileStream(filePath);
    std::pair<std::pair<Disease,char*>,char*>ans=std::make_pair(std::make_pair(Disease(),nullptr),(nullptr));
    // Check if the file exists
    if (fileStream.good()) {
        int IdToCheckAppointment;
        std::cout<<"Enter the Id of the Patient you want to Arrange Appointment For: ";
        std::cin>>IdToCheckAppointment;

        std::ifstream IfPatient;
        IfPatient.open(PatientFile,std::ios::in|std::ios::binary);

        while(!IfPatient.eof()){

            IfPatient.read((char*)this,sizeof(Patient));
            if(IfPatient){
                if(IdToCheckAppointment==PatientId){
                    ans = std::make_pair(std::make_pair(PatientDisease,AppointmentDate),AppointmentDay);
                }
            }

        }

        IfPatient.close();
        if(ans.second== nullptr||ans.first.second== nullptr)
            std::cout<<"Record not Found "<<line;
    }else{
        std::cout<<"There is no patients"<<line;
    }
    // Close the file stream
    fileStream.close();
    return ans;
}
