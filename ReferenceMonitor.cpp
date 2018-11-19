#include "ReferenceMonitor.h"
#include "Subject.h"
#include "Object.h"
#include <cctype>
#include <string>
#include <functional>
void ReferenceMonitor::addSubject(string a, string b, string sub_l){
  //first check if the subject tend to add existed already, if does, reject to change the secuirty level

  vector<string>::iterator sub_it; //sub_it is a iterator used for go through the list
  sub_it = find(sub.name.begin(),sub.name.end(),b);
  int p1 = sub_it-sub.name.begin();
  if(sub_it != sub.name.end()){
    cout<<"Access Denied, subject "<<b<<" has already existed, do not allow changing security level"<<endl;
  }else{
    //if not exist, add to the vector list
    std::transform(sub_l.begin(),sub_l.end(),sub_l.begin(),::tolower); //convert to lower case
    sub.name.push_back(b);
    sub.temp.push_back(0);
    refe.label_sub.push_back(sub_l);
    cout<<"Add Subject: "<<a<<" "<<b<<" "<<sub_l<<endl;
  }
}

void ReferenceMonitor::addObject(string a, string b, string obj_l){
  //first check if the subject tend to add existed already, if does, reject to change the secuirty level
  vector<string>::iterator obj_it;//obj_it is a iterator used for go through the list
  obj_it = find(obj.name.begin(),obj.name.end(),b);
  int p2 = obj_it-obj.name.begin();
  if(obj_it != obj.name.end()){
    cout<<"Access Denied, object "<<b<<" has already existed, do not allow changing change security level"<<endl;
  }else{
    std::transform(obj_l.begin(),obj_l.end(),obj_l.begin(),::tolower);//convert to lower case
    //if not exist, add to the vector list
    obj.name.push_back(b);
    obj.value.push_back(0);
    refe.label_obj.push_back(obj_l);
    cout<<"Add Object: "<<a<<" "<<b<<" "<<obj_l<<endl;
  }

}

void ReferenceMonitor::executeRead(string a, string b){

  //we will check if the given subject and object existed already or not since we want to read. If not exist, we return invalide sub or obj
  vector<string>::iterator sub_it; //iterator
  vector<string>::iterator obj_it; //iterator
  sub_it = find(sub.name.begin(),sub.name.end(),a);
  obj_it = find(obj.name.begin(),obj.name.end(),b);
  int p1 = sub_it-sub.name.begin(); //p1 is the posistion of the subject in the vector
  int p2 = obj_it-obj.name.begin(); //p2 is the posistion of the subject in the vector
  if(sub_it != sub.name.end()){
    //cout<<"The subject is at posistion   "<<*sub_it+"   "<<sub_it-sub.name.begin()<<endl; //if exist, doing noting
  }else{
    cout<<"Invalid Subject"<<endl;
  }

  if(obj_it != obj.name.end()){
    //cout<<"The object is at posistion   "<<*obj_it+"  "<<obj_it-obj.name.begin()<<endl; //if exist, doing noting
  }else{
    cout<<"Invalid object"<<endl;
  }
  //the following block of code is implementing Bell-LaPadula security model. Basiclly No read up, no write down.
  if((refe.label_sub.at(p1) == "LOW" || refe.label_sub.at(p1) == "low" ) && (refe.label_obj.at(p2) == "LOW" || refe.label_obj.at(p2) == "low")){
    sub.temp.at(p1) = obj.value.at(p2);
    cout<<"Access Granted : "<<a<<" read "<<b<<endl;
  }else if((refe.label_sub.at(p1) == "LOW" || refe.label_sub.at(p1) == "low") && (refe.label_obj.at(p2) == "MEDIUM" || refe.label_obj.at(p2) == "medium")){
    cout<<"Access Denied :"<<" read "<<a<<" "<<b<<endl;
  }else if((refe.label_sub.at(p1) == "LOW" || refe.label_sub.at(p1) == "low") && (refe.label_obj.at(p2) == "HIGH" || refe.label_obj.at(p2) == "high")){
    cout<<"Access Denied :"<<" read "<<a<<" "<<b<<endl;
  }else if((refe.label_sub.at(p1) == "MEDIUM" || refe.label_sub.at(p1) == "medium") && (refe.label_obj.at(p2) == "LOW" || refe.label_obj.at(p2) == "low")){
    sub.temp.at(p1) = obj.value.at(p2);
    cout<<"Access Granted : "<<a<<" read "<<b<<endl;
  }else if((refe.label_sub.at(p1) == "MEDIUM" || refe.label_sub.at(p1) == "medium") && (refe.label_obj.at(p2) == "MEDIUM" || refe.label_obj.at(p2) == "medium")){
    sub.temp.at(p1) = obj.value.at(p2);
    cout<<"Access Granted : "<<a<<" read "<<b<<endl;
  }else if((refe.label_sub.at(p1) == "MEDIUM" || refe.label_sub.at(p1) == "medium") && (refe.label_obj.at(p2) == "HIGH" || refe.label_obj.at(p2) == "high")){
    cout<<"Access Denied :"<<" read "<<a<<" "<<b<<endl;
  }else if((refe.label_sub.at(p1) == "HIGH" || refe.label_sub.at(p1) == "high") && (refe.label_obj.at(p2) == "LOW" || refe.label_obj.at(p2) == "low")){
    sub.temp.at(p1) = obj.value.at(p2);
    cout<<"Access Granted : "<<a<<" read "<<b<<endl;
  }else if((refe.label_sub.at(p1) == "HIGH" || refe.label_sub.at(p1) == "high") && (refe.label_obj.at(p2) == "MEDIUM" || refe.label_obj.at(p2) == "medium")){
    sub.temp.at(p1) = obj.value.at(p2);
    cout<<"Access Granted : "<<a<<" read "<<b<<endl;
  }else if((refe.label_sub.at(p1) == "HIGH" || refe.label_sub.at(p1) == "high") && (refe.label_obj.at(p2) == "HIGH" || refe.label_obj.at(p2) == "high")){
    sub.temp.at(p1) = obj.value.at(p2);
    cout<<"Access Granted : "<<a<<" read "<<b<<endl;
  }
}

void ReferenceMonitor::executeWrite(string a, string b, int c){
  //we will check if the given subject and object existed already or not since we want to read. If not exist, we return invalide sub or obj
  vector<string>::iterator sub_it; //iterator
  vector<string>::iterator obj_it;//iterator
  sub_it = find(sub.name.begin(),sub.name.end(),a);
  obj_it = find(obj.name.begin(),obj.name.end(),b);
  int p1 = sub_it-sub.name.begin(); //p1 is the posistion of the subject in the vector
  int p2 = obj_it-obj.name.begin(); //p2 is the posistion of the subject in the vector
  if(sub_it != sub.name.end()){
    //cout<<"The subject is at posistion   "<<*sub_it+"   "<<sub_it-sub.name.begin()<<endl;
  }else{
    cout<<"Invalid Subject"<<endl;
  }

  if(obj_it != obj.name.end()){
    //cout<<"The object is at posistion   "<<*obj_it+"  "<<obj_it-obj.name.begin()<<endl;
  }else{
    cout<<"Invalid object"<<endl;
  }
  //the following block of code is implementing Bell-LaPadula security model. Basiclly No read up, no write down.
  if((refe.label_sub.at(p1) == "LOW" || refe.label_sub.at(p1) == "low") && (refe.label_obj.at(p2) == "LOW" || refe.label_obj.at(p2) == "low")){
    cout<<"Access Granted : "<<a<<" writes value "<<c<<" to "<<b<<endl;
    obj.value.at(p2) = c;
  }else if((refe.label_sub.at(p1) == "LOW" || refe.label_sub.at(p1) == "low") && (refe.label_obj.at(p2) == "MEDIUM" || refe.label_obj.at(p2) == "medium")){
    cout<<"Access Granted : "<<a<<" writes value "<<c<<" to "<<b<<endl;
    obj.value.at(p2) = c;
  }else if((refe.label_sub.at(p1) == "LOW" || refe.label_sub.at(p1) == "low") && (refe.label_obj.at(p2) == "HIGH" || refe.label_obj.at(p2) == "high")){
    cout<<"Access Granted : "<<a<<" writes value "<<c<<" to "<<b<<endl;
    obj.value.at(p2) = c;
  }else if((refe.label_sub.at(p1) == "MEDIUM" || refe.label_sub.at(p1) == "medium") && (refe.label_obj.at(p2) == "LOW" || refe.label_obj.at(p2) == "low")){
    cout<<"Access Denied :"<<" write "<<a<<" "<<b<<" "<<c<<endl;
  }else if((refe.label_sub.at(p1) == "MEDIUM" || refe.label_sub.at(p1) == "medium")&& (refe.label_obj.at(p2) == "MEDIUM" || refe.label_obj.at(p2) == "medium")){
    cout<<"Access Granted : "<<a<<" writes value "<<c<<" to "<<b<<endl;
    obj.value.at(p2) = c;
  }else if((refe.label_sub.at(p1) == "MEDIUM" || refe.label_sub.at(p1) == "medium") && (refe.label_obj.at(p2) == "HIGH" || refe.label_obj.at(p2) == "high")){
    cout<<"Access Granted : "<<a<<" writes value "<<c<<" to "<<b<<endl;
    obj.value.at(p2) = c;
  }else if((refe.label_sub.at(p1) == "HIGH" || refe.label_sub.at(p1) == "high") && (refe.label_obj.at(p2) == "LOW" || refe.label_obj.at(p2) == "low")){
    cout<<"Access Denied :"<<" write "<<a<<" "<<b<<" "<<c<<endl;
  }else if((refe.label_sub.at(p1) == "HIGH" || refe.label_sub.at(p1) == "high") && (refe.label_obj.at(p2) == "MEDIUM" || refe.label_obj.at(p2) == "medium")){
    cout<<"Access Denied :"<<" write "<<a<<" "<<b<<" "<<c<<endl;
  }else if((refe.label_sub.at(p1) == "HIGH" || refe.label_sub.at(p1) == "high") && (refe.label_obj.at(p2) == "HIGH" || refe.label_obj.at(p2) == "high")){
    cout<<"Access Granted : "<<a<<" writes value "<<c<<" to "<<b<<endl;
    obj.value.at(p2) = c;
  }
}

void ReferenceMonitor::printState(){
  //print out the state
  cout<<"+---current state---+"<<endl;
  cout<<"|-subject-|"<<"  "<<"|-temp-|"<<endl;//" "<<"|-label-|"<<endl;
  for(int i=0;i<sub.name.size();i++){
    cout<<"  " + sub.name[i]<<"       "<<sub.temp[i]<<endl;//"       "<<refe.label_sub[i]<<endl;
  }
  cout<<"|-object-|"<<"  "<<"|-value-|"<<endl;
  for(int i=0;i<obj.name.size();i++){
    cout<<"  " + obj.name[i]<<"       "<<obj.value[i]<<endl;//"      "<<refe.label_obj[i]<<endl;
  }

}
