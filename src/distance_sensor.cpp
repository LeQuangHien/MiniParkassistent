#include "distance_sensor.hpp"
#include <wiringPi.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <iostream>

HCSR04Sensor::HCSR04Sensor(int trigger_pin, int echo_pin)
    : trigger_pin_(trigger_pin), echo_pin_(echo_pin) {
    wiringPiSetupGpio();
    pinMode(trigger_pin_, OUTPUT);
    pinMode(echo_pin_, INPUT);
}

float HCSR04Sensor::get_distance_cm() {
    digitalWrite(trigger_pin_, LOW);
    std::this_thread::sleep_for(std::chrono::microseconds(2));
    digitalWrite(trigger_pin_, HIGH);
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    digitalWrite(trigger_pin_, LOW);

    auto start = std::chrono::high_resolution_clock::now();
    while (digitalRead(echo_pin_) == LOW);
    start = std::chrono::high_resolution_clock::now();

    while (digitalRead(echo_pin_) == HIGH);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    float distance = duration.count() * 17150.0f;

    return distance;
}

std::string HCSR04Sensor::get_name() const {
    return "HC-SR04";
}

VL53L0XSensor::VL53L0XSensor() {}

float VL53L0XSensor::get_distance_cm() {
    return 50.0f;
}

std::string VL53L0XSensor::get_name() const {
    return "VL53L0X";
}
