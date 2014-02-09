# Makefile for Program#1: client.cpp, printer.cpp, and printer.h
# To use this makefile, in terminal type "make" or alternatively 
# "make -f Makefile".
# To remove the object files created type "make clean" in terminal.




CC = g++			# tells make to use compiler g++ by default by binding CC to g++

all: program


program: client.cpp printer.cpp
	$(CC) client.o printer.o -o hello

					#removes all files with the .o extension
clean:
	rm -rf *o program
