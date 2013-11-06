# This Makefile is written for GNU Make
#
# Maintain the following definitions:
#
# HDR       all header files (*.h) that you create
# SRC       all C++ source files (*.cpp) that you create
# OBJ       all object files (*.o) required to load your program
# EXE       the name of the executable
# PRT       your favorite printer
# GRD       all files required for grading
#
# Use the following make targets:
#
# all       (the default) to build your program (into ${EXE})
# clean     to remove unnecessary files
# veryclean to remove eveything but source files
# list      to list files changed since the last listing
# listall   to list your complete program
# submit    to hand in your program for grading
# depend    to update header file dependencies

HDR  =	timer.h AVLTree.h 
SRC  =	timer.cpp main.cpp AVLTree.cpp 
OBJ  =	timer.o main.o AVLTree.o 
EXE  =	ALVTree 
PRT  =	lp2 
GRD  =	README Makefile ${HDR} ${SRC}

DEP =	${SRC}
CFLAGS= -g

# Use g++ as C compiler as well
CC =	g++
CPP =	g++

.PHONY: all clean veryclean listall submit depend

all: ${EXE}

${EXE}: ${OBJ}
	${CPP} ${CFLAGS} -o ${EXE} ${OBJ}

clean:
	rm -f ${OBJ} core

veryclean:
	rm -f ${OBJ} core
	rm -f Makefile.bak ${EXE} list *~

list: ${GRD}
	@lp -d ${PRT} -o duplex ${GRD}
	@echo "Update: `date`" >> list

listall:
	@lp -d ${PRT} -o duplex ${GRD}
	@echo "Complete: `date`" >> list

.SUFFIXES: .cpp

%.o: %.cpp
	${CPP} ${CFLAGS} -c -o $*.o $*.cpp

depend: ${SRC} ${SRCg}
	cp -p Makefile Makefile.bak
	awk '{ print $0; } /(make) (depend)/ { exit; }' Makefile.bak > Makefile
	echo "" >> Makefile
	${CPP} ${CFLAGS} -MM ${SRC} ${SRCg} >> Makefile
	echo "" >> Makefile
	echo "# *** Do not add anything here - It will go away. ***" >>Makefile

# DO NOT DELETE THIS LINE - make depend DEPENDS ON IT

main.o: main.cpp AVLTree.h timer.h
AVLTree.o: AVLTree.cpp AVLTree.h
timer.o: timer.cpp timer.h

# *** Do not add anything here - It will go away. ***
