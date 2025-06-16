#include "distance_sensor.hpp"
#include <wiringPi.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <iostream>

HCSR04Sensor::HCSR04Sensor(int trigger_pin, int echo_pin)
    : trigger_pin_(trigger_pin), echo_pin_(echo_pin) {
    wiringPiSetupGpio(); // BCM-Nummerierung
    pinMode(trigger_pin_, OUTPUT);
    pinMode(echo_pin_, INPUT);
    digitalWrite(trigger_pin_, LOW); // Initial LOW
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Stabilisierung
}

bool HCSR04Sensor::wait_for_pin_state(int pin, bool state, int timeout_us) {
    auto start = std::chrono::high_resolution_clock::now();
    while (digitalRead(pin) != state) {
        auto now = std::chrono::high_resolution_clock::now();
        if (now - start > std::chrono::microseconds(timeout_us)) {
            return false;
        }
    }
    return true;
}

float HCSR04Sensor::get_distance_cm() {
    // Ultraschall senden
    digitalWrite(trigger_pin_, LOW);
    std::this_thread::sleep_for(std::chrono::microseconds(2));
    digitalWrite(trigger_pin_, HIGH);
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    digitalWrite(trigger_pin_, LOW);

    // Warten auf Echo-Start
    if (!wait_for_pin_state(echo_pin_, HIGH, 30000)) {
        std::cerr << "Timeout: Kein Echo-Start empfangen\n";
        return -1.0f;
    }
    auto start = std::chrono::high_resolution_clock::now();

    // Warten auf Echo-Ende
    if (!wait_for_pin_state(echo_pin_, LOW, 30000)) {
        std::cerr << "Timeout: Echo blieb HIGH\n";
        return -1.0f;
    }
    auto end = std::chrono::high_resolution_clock::now();

    // Distanz berechnen
    std::chrono::duration<float> duration = end - start;
    float distance = duration.count() * 17150.0f; // Schallgeschwindigkeit: 34300 cm/s / 2

    return distance;
}

std::string HCSR04Sensor::get_name() const {
    return "HC-SR04";
}

// Dummy-Implementierung für VL53L0X
VL53L0XSensor::VL53L0XSensor() {
    // Hier würde I2C-Initialisierung erfolgen
}

float VL53L0XSensor::get_distance_cm() {
    // Platzhalterwert
    return 50.0f;
}

std::string VL53L0XSensor::get_name() const {
    return "VL53L0X";
}
