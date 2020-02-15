CC = g++
BUILD_DIR = build
OUTPUT = gsw
INSTALL_DIR = 
CL =
CP =
RM =

ifeq ($(OS),Windows_NT)
	INSTALL_DIR += $(SystemRoot)
	CL += rmdir $(BUILD_DIR) /S /Q
	CP += copy $(BUILD_DIR)\$(OUTPUT).exe $(INSTALL_DIR) && echo alias gsw="gsw.exe" >> $(USERPROFILE)\.bash_profile
	RM += del $(INSTALL_DIR)\$(OUTPUT).exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		INSTALL_DIR += /usr/bin
		CL += rm $(BUILD_DIR) -r
		CP += cp $(BUILD_DIR)/$(OUTPUT) $(INSTALL_DIR)
		RM += rm $(INSTALL_DIR)/$(OUTPUT)
    endif
endif

main:
	mkdir build
	g++ src/main.cpp -o $(BUILD_DIR)/$(OUTPUT)
all:
	make
	make install
	make clean
clean:
	$(CL)
install:
	$(CP)
uninstall:
	$(RM)
