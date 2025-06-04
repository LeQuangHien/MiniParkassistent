#include "distance_sensor.hpp"
#include "webserver.hpp"
#include "led_buzzer.hpp"
#include <iostream>
#include <thread>
#include <memory>

std::shared_ptr<DistanceSensor> active_sensor;
float current_distance = 0.0f;
bool running = true;

void sensor_loop() {
    while (running) {
        current_distance = active_sensor->get_distance_cm();
        set_warning(current_distance);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    active_sensor = std::make_shared<HCSR04Sensor>(17, 27);
    std::thread t(sensor_loop);
    start_webserver(current_distance);
    running = false;
    t.join();
    return 0;
}
