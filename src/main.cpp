#include "distance_sensor.hpp"
#include "led_buzzer.hpp"
#include "webserver.hpp"
#include <wiringPi.h>
#include <iostream>
#include <thread>
#include <chrono>

float current_distance = 0.0f;
constexpr int TRIGGER_PIN = 23; // GPIO23
constexpr int ECHO_PIN = 24;    // GPIO24

int main() {
    wiringPiSetupGpio(); // BCM-Pin-Nummern
    setup_led_buzzer();  // Initialisiere LED/Buzzer-Pins

    HCSR04Sensor sensor(TRIGGER_PIN, ECHO_PIN);
    std::thread server_thread(start_webserver, std::ref(current_distance));

    while (true) {
        current_distance = sensor.get_distance_cm();
        std::cout << "Entfernung: " << current_distance << " cm" << std::endl;
        set_warning(current_distance);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
