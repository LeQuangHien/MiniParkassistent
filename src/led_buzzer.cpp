#include "led_buzzer.hpp"
#include <wiringPi.h>

constexpr int LED_RED_PIN = 11;
constexpr int LED_YELLOW_PIN = 13;
constexpr int LED_GREEN_PIN = 15;
constexpr int BUZZER_PIN = 12;

void set_warning(float distance_cm) {
    if (distance_cm < 10.0f) {
        digitalWrite(LED_RED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
    } else if (distance_cm < 25.0f) {
        digitalWrite(LED_YELLOW_PIN, HIGH);
        digitalWrite(BUZZER_PIN, LOW);
    } else {
        digitalWrite(LED_GREEN_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
    }
}
