# Makefile 
CC=g++
CPPFLAGS=-c -pedantic -Wall -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable

AR= ar rvs

BIN_PATH= bin/
OBJ_PATH= obj/
INC_PATH= inc/
SRC_PATH= src/

all: staticLib 

staticLib: $(OBJ_PATH)SIM868.o
	$(AR) $(BIN_PATH)libSIM868.a $(OBJ_PATH)SIM868.o

$(OBJ_PATH)SIM868.o: $(SRC_PATH)SIM868.cpp $(INC_PATH)SIM868.h
	$(CC) $(CPPFLAGS) $(SRC_PATH)SIM868.cpp 
	mv SIM868.o $(OBJ_PATH)
	
clean:
	 -rm -f $(OBJ_PATH)*.o *.d $(BIN_PATH)*.a
	 -rm -rf $(ZIP_FILE)
