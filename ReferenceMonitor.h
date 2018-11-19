#ifndef REFERENCEMONITOR_H
#define REFERENCEMONITOR_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
//static only allows class used at local, prevent conflict, define functions
static class ReferenceMonitor {
  private:
    vector <string> label_sub;
    vector <string> label_obj;
  public:
    static void addSubject(string a, string b, string sub_l);
    static void addObject(string a, string b, string obl_l);
    static void executeRead(string , string );
    static void executeWrite(string ,string ,int );
    static void printState();
}refe;

#endif
