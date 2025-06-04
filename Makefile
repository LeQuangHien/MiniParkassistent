CXX = g++
CXXFLAGS = -Wall -std=c++17 -lwiringPi -lmicrohttpd

SRC = src/main.cpp src/distance_sensor.cpp src/webserver.cpp src/led_buzzer.cpp
INCLUDE = -Iinclude
TARGET = park_assistant

all:
	$(CXX) $(SRC) $(INCLUDE) -o $(TARGET) $(CXXFLAGS)
