CC = g++
BUILD_DIR = build
SOURCE_DIR = src
EXECUTABLE = gsw

SOURCES = $(addprefix $(SOURCE_DIR)\\*, .cpp \\*.cpp)

INSTALL_DIR = 
CL =
INST =
UINST =

ifeq ($(OS),Windows_NT)
	INSTALL_DIR += $(SystemRoot)
	CL += rmdir $(BUILD_DIR) /S /Q
	INST += copy $(BUILD_DIR)\$(EXECUTABLE).exe $(INSTALL_DIR)
	UINST += del $(INSTALL_DIR)\$(EXECUTABLE).exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		INSTALL_DIR += /usr/bin
		CL += rm $(BUILD_DIR) -r
		INST += cp $(BUILD_DIR)/$(EXECUTABLE) $(INSTALL_DIR)
		UINST += rm $(INSTALL_DIR)/$(EXECUTABLE)
    endif
endif

main:
	mkdir $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)\$(EXECUTABLE) $(SOURCES)

all:
	make
	make install
	make clean

clean:
	$(CL)

install:
	$(INST)

update:
	make uninstall
	make all

uninstall:
	$(UINST)
