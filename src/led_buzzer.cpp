#include "led_buzzer.hpp"
#include <wiringPi.h>

constexpr int LED_RED_PIN = 11;     // GPIO17
constexpr int LED_YELLOW_PIN = 13;  // GPIO27
constexpr int LED_GREEN_PIN = 15;   // GPIO22
constexpr int BUZZER_PIN = 12;      // GPIO18

enum class WarningLevel {
    SAFE,
    CAUTION,
    DANGER
};

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
    static WarningLevel last_level = WarningLevel::SAFE;

    WarningLevel current_level;
    if (distance_cm < 10.0f) {
        current_level = WarningLevel::DANGER;
    } else if (distance_cm < 25.0f) {
        current_level = WarningLevel::CAUTION;
    } else {
        current_level = WarningLevel::SAFE;
    }

    if (current_level == last_level) return;  // Kein Zustand geändert → nichts tun
    last_level = current_level;

    // Erst alles ausschalten
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_YELLOW_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    // Dann je nach Zustand einschalten
    switch (current_level) {
        case WarningLevel::DANGER:
            digitalWrite(LED_RED_PIN, HIGH);
            digitalWrite(BUZZER_PIN, HIGH);
            break;
        case WarningLevel::CAUTION:
            digitalWrite(LED_YELLOW_PIN, HIGH);
            break;
        case WarningLevel::SAFE:
            digitalWrite(LED_GREEN_PIN, HIGH);
            break;
    }
}
