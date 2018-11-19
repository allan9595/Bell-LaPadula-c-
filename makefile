# build a program from 2 files and one shared header
CC = g++
CFLAGS = -g -std=c++11

BLPsecure: BLPsecure.cpp ReferenceMonitor.cpp
	$(CC) $(CFLAGS) -o BLPsecure BLPsecure.cpp ReferenceMonitor.cpp
