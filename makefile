# Makefile 
CC=g++
CPPFLAGS= -pedantic -Wall -lpthread -lrt -Wfatal-errors -Wextra -Wunused-variable -Wunused-parameter
SIM_PATH = /home/ismail/Documents/GSM_driver/SIM868
ZIP_FILE = App.zip
COLLECTED_FILES = SIM868.h SIM868.cpp main.cpp
SIM868LIB = -L$(SIM_PATH)/bin -Wl,-rpath,$(SIM_PATH)/bin -l SIM868
SIM868INC = -I$(SIM_PATH)/inc
APP_PATH = Application/

all: main.o #zip

main.o: 
	g++ $(APP_PATH)main.cpp $(CPPFLAGS) $(SIM868INC) $(SIM868LIB) -o $(APP_PATH)App 

zip:
	@echo "Removing any previous version of zip file..."
	rm -rf $(ZIP_FILE)
	@echo "Creating new zip file..."
	zip $(ZIP_FILE) $(COLLECTED_FILES)
	@echo "Created zip file: " $(ZIP_FILE)	
	
clean:
	 -rm -f *.o *.d $(APP_PATH)App
#	 -rm -rf $(ZIP_FILE)
