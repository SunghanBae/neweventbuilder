#TARGET = hitbuild_iononly
GO4SYS = /media/bae/data1/research/RIKEN/201605~06_EURICA/go4-5.2.0
OBJ = newevent

all: $(OBJ)

include $(GO4SYS)/Makefile.config

CXX	= g++
#LIBS            = -L/usr/local/lib -lXMLParser
ROOTCFLAGS	= $(shell root-config --cflags)
ROOTLIBS	= $(shell root-config --libs)
ROOTGLIBS	= $(shell root-config --glibs)
#TARTLIBS        = -L$(TARTSYS)/lib -lanacore -lanaroot -lanabrips -lanawinds -lanaloop -lanacore -L/usr/local/lib -lXMLParser
INCLUDES	= -I$(ROOTSYS)/include


ifdef GO4_WIN32
   GO4SYS = ../go4
endif

newevent: eventbuilder.cpp AIDA_parsed.h
	$(CXX) $< -fstack-protector-all -o $@ $(INCLUDES) $(ROOTLIBS) $(ROOTCFLAGS) $(ROOTGLIBS) 


clean: 
	rm -f $(OBJ) *.o
