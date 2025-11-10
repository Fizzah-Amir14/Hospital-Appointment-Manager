#include <iostream>
#include <string>
using namespace std;

class HospitalAppoint {
private:
    
    struct node {
        string patientName;
        int patientID;
        string doctorName;
        string appointmentTime;
        node* next;

       
        // node(string pName, int pID, string dName, string aTime)
        //     : patientName(pName), patientID(pID), doctorName(dName), appointmentTime(aTime), next(nullptr) {}
    };
    node* head; 
public:
    
    HospitalAppoint() {
        head=NULL; }

    void addPatient(string pName, int pID, string dName, string aTime){
        node *newnode=new node{pName,pID,  dName,  aTime,NULL};
        if(head==NULL) {head=newnode;
        return;}
        // if(head->next==NULL) head->next=newnode;
        else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=newnode;
        }
    }
   void callNextPatient(){
       if(head==NULL) 
       {cout<<"Appointment List is empty:"<<endl;
       return;}
       else{
           node *tode=head;
            if(head->next==NULL){
               
               cout<<"Last Patient:\n"<<"Patient Name: "<<head->patientName<<
           "Patient Id: "<<head->patientID<<"Doctor Name: "<<head->doctorName<<"Appointment Time:"<<head->
           appointmentTime<<endl;
           head=NULL;
           }else{
               cout<<"Patient Name: "<<head->patientName<<
           "Patient Id: "<<head->patientID<<"Doctor Name: "<<head->doctorName<<"Appointment Time:"<<head->
           appointmentTime<<endl;
           
           head=head->next;
               
           }
           delete tode;
       }
   }
      void displayAllAppointments(){
          if(head==NULL){
              cout<<"Appointment List empty:"<<endl;
              return;
          }else{
              node *temp=head;
              while(temp!=NULL){
                  cout<<"Patient Name: "<<head->patientName<<
           "Patient Id: "<<head->patientID<<"Doctor Name: "<<head->doctorName<<"Appointment Time:"<<head->
           appointmentTime<<endl;
           temp=temp->next;
              }
          }
      }
   
};

int main() {
    HospitalAppoint hos;
   hos.addPatient("Ali", 101, "Dr. Khan", "10:00 AM");
    hos.addPatient("Sara", 102, "Dr. Fatima", "10:30 AM");
    hos.addPatient("Zain", 103, "Dr. Ahmed", "11:00 AM");

    cout << "All Appointments:\n";
    hos.displayAllAppointments();
     cout << "\n Calling Patients \n";
    hos.callNextPatient();
    hos.callNextPatient();
    hos.callNextPatient();
    hos.callNextPatient();


    return 0;
}
