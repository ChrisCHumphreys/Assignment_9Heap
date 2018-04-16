# File: Makefile
# Date: 04/16/18
# Author: Chris Humphreys
#   -> Adapeted from Makefile by Joshua Gearin
# Description: Makefile assignment 9 -> heap(CSCI325)

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Memory Mangagment Flags
MEMFLAGS=-fsanitize=address -fno-omit-frame-pointer

# Target
TARGET=heap_driver

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

# Makefile syntax:
# target: dependencies
#(tab) system command(s)

all: $(TARGET)

$(TARGET): main.o heap.o
	$(CC) main.o heap.o -o $(TARGET) $(MEMFLAGS)

main.o: main.cpp heap.h
	$(CC) $(CFLAGS) $(MEMFLAGS) main.cpp

heap.o: heap.cpp heap.h
	$(CC) $(CFLAGS) $(MEMFLAGS) heap.cpp

clean:
	rm -f *.o *~ *.swp $(TARGET)

