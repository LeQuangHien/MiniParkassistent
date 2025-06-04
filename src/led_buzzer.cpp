#include "led_buzzer.hpp"
#include <wiringPi.h>

constexpr int LED_PIN = 22;
constexpr int BUZZER_PIN = 23;

void set_warning(float distance_cm) {
    if (distance_cm < 10.0f) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
    } else if (distance_cm < 25.0f) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, LOW);
    } else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
    }
}
