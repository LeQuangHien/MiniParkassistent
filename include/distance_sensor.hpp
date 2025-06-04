#pragma once
#include <string>

class DistanceSensor {
public:
    virtual ~DistanceSensor() = default;
    virtual float get_distance_cm() = 0;
    virtual std::string get_name() const = 0;
};

class HCSR04Sensor : public DistanceSensor {
public:
    HCSR04Sensor(int trigger_pin, int echo_pin);
    float get_distance_cm() override;
    std::string get_name() const override;
private:
    int trigger_pin_;
    int echo_pin_;
};

class VL53L0XSensor : public DistanceSensor {
public:
    VL53L0XSensor();
    float get_distance_cm() override;
    std::string get_name() const override;
};
