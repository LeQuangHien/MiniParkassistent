#include "distance_sensor.hpp"
#include <wiringPi.h>
#include <iostream>
#include <thread>
#include <chrono>

// GPIO-Pins (BCM-Nummerierung!)
constexpr int TRIGGER_PIN = 23;    // GPIO23
constexpr int ECHO_PIN = 24;       // GPIO24
constexpr int RED_LED_PIN = 17;    // GPIO17
constexpr int YELLOW_LED_PIN = 27; // GPIO27
constexpr int GREEN_LED_PIN = 22;  // GPIO22
constexpr int BUZZER_PIN = 18;     // GPIO18

void setup_output_pins() {
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
}

void update_outputs(float distance) {
    // Alles ausschalten
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    if (distance < 0) {
        std::cout << "Fehlerhafte Messung\n";
        return;
    }

    std::cout << "Entfernung: " << distance << " cm\n";

    if (distance <= 10.0f) {
        digitalWrite(RED_LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
    } else if (distance <= 25.0f) {
        digitalWrite(YELLOW_LED_PIN, HIGH);
    } else {
        digitalWrite(GREEN_LED_PIN, HIGH);
    }
}

int main() {
    wiringPiSetupGpio(); // BCM-Nummerierung
    setup_output_pins();

    HCSR04Sensor sensor(TRIGGER_PIN, ECHO_PIN);

    while (true) {
        float distance = sensor.get_distance_cm();
        update_outputs(distance);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
