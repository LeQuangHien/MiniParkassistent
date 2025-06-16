#include "distance_sensor.hpp"
#include "led_buzzer.hpp"
#include <wiringPi.h>
#include <iostream>
#include <thread>
#include <chrono>

constexpr int TRIGGER_PIN = 23; // GPIO23
constexpr int ECHO_PIN = 24;    // GPIO24

int main() {
    wiringPiSetupGpio(); // BCM-Pin-Nummern
    setup_led_buzzer();  // Initialisiere LED/Buzzer-Pins

    HCSR04Sensor sensor(TRIGGER_PIN, ECHO_PIN);

    while (true) {
        float distance = sensor.get_distance_cm();
        std::cout << "Entfernung: " << distance << " cm" << std::endl;
        set_warning(distance);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
