DATE: 10-13-2018

LICENSE: MIT

Description:

This program simulates a simple secure system with Bell-LaPadula built-in security features (No read up, No write down). This program takes a instruction file created by you. The instruction file should certain instructions to let the program add subjects and objects and change their values based on the security model.

Notice:
if you see this message:

make: Warning: File 'ReferenceMonitor.cpp' has modification time 5.5e+03 s in the future

g++  -g -std=c++11  -o BLPsecure BLPsecure.cpp ReferenceMoni'

make: warning:  Clock skew detected.  Your build may be incomplete.

Try to use touch to reset the timestamp and make again !

Available Instructions :

addsub subject security_label

addobj object security_label

read subject object

write subject object value(ex: 10)

When you make instruct list, please make sure using one single white space between each string!

usage:

make

./BLPsecure you_instruction_file

Happy Coding
