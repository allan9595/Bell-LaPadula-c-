#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <string>
#include <functional>
#include "ReferenceMonitor.h"
#include "instruction.h"
using namespace std;

/*
The main function reads the instruction file, parsing command and add sub , obj to their related class objects
*/
int main(int argc, char *argv[]){
  int count = 0; //track the action times
  if(argc == 1){
    cout<<"Usage: BLPsecure instructionList \n";
  } else if(argc == 2) {

    string data, intermediate; //define the data to store each line
    ifstream infile; //define a file object variable
    infile.open(argv[1]);
    //if file not exisiting, then return bad file
    if(!infile){
      cout<<"badfile"<<endl;
      return 0;
    }
    vector <string> tokens;

    while(infile){
      //print_state for every 10 actions
      if(count % 10 == 0){
        refe.printState();
      }
      getline(infile,data);
      istringstream split(data);

      for (string each; getline(split, each, ' '); tokens.push_back(each)); //split the line data based on ' '
      std::transform(tokens[0].begin(),tokens[0].end(),tokens[0].begin(),::tolower);//convert to lower case
      if(tokens[0] == "addsub"){
        instruct.addsub.push_back(tokens[0]);
        refe.addSubject(tokens[0],tokens[1],tokens[2]); //parsing the instruction into the addsub if it's addsub

      }else if(tokens[0] == "addobj"){
        instruct.addobj.push_back(tokens[0]);
        refe.addObject(tokens[0],tokens[1],tokens[2]); //parsing the instruction into the addobj if it's addobj

      }else if(tokens[0] == "read"){
        refe.executeRead(tokens[1],tokens[2]); //read the Obejct from the subject
      }else if(tokens[0] == "write"){
        refe.executeWrite(tokens[1],tokens[2],stoi(tokens[3])); //write a new value to the object
      }else {
        cout<<"Bad instruction: "<<tokens[0]<<" "<<tokens[1]<<" "<<tokens[2]<<" "<<tokens[3]<<endl;
      }
      tokens.clear(); //clear the tokens which contains parsed instruction so it can move to next line

      count = count + 1; //track the action time
    }
    tokens.clear();

    infile.close(); //close the file
  }
  return 0;
}
