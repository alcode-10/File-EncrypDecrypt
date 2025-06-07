# === Makefile for Encrypty ===

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC_DIR = src/app
ENCRYPT_DIR = $(SRC_DIR)/encryptDecrypt
FILE_DIR = $(SRC_DIR)/fileHandling
PROCESS_DIR = $(SRC_DIR)/processes

OBJS = main.o \
       $(ENCRYPT_DIR)/Cryption.o \
       $(FILE_DIR)/IO.o \
       $(FILE_DIR)/ReadEnv.o \
       $(PROCESS_DIR)/ProcessManagement.o

TARGET = File-EncryptDecrypt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

$(ENCRYPT_DIR)/Cryption.o: $(ENCRYPT_DIR)/Cryption.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(FILE_DIR)/IO.o: $(FILE_DIR)/IO.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(FILE_DIR)/ReadEnv.o: $(FILE_DIR)/ReadEnv.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PROCESS_DIR)/ProcessManagement.o: $(PROCESS_DIR)/ProcessManagement.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
