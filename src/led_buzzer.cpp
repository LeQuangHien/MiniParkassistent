#include "led_buzzer.hpp"
#include <wiringPi.h>

constexpr int LED_RED_PIN = 17;     // GPIO17
constexpr int LED_YELLOW_PIN = 27;  // GPIO27
constexpr int LED_GREEN_PIN = 22;   // GPIO22
constexpr int BUZZER_PIN = 18;      // GPIO18

void setup_led_buzzer() {
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_YELLOW_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_YELLOW_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
}

void set_warning(float distance_cm) {
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_YELLOW_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    if (distance_cm < 10.0f) {
        digitalWrite(LED_RED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
    } else if (distance_cm < 25.0f) {
        digitalWrite(LED_YELLOW_PIN, HIGH);
    } else {
        digitalWrite(LED_GREEN_PIN, HIGH);
    }
}
