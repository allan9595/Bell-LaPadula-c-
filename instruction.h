#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

class instruction {
  public:
    vector <string> addsub;
    vector <string> addobj;
    vector <string> read;
    vector <string> write;
}instruct;

#endif
