# 🚗 Mini Parkassistent mit Raspberry Pi, C++ und Webinterface (🚧 In Arbeit)

Dies ist ein einfaches Embedded-Projekt mit dem Raspberry Pi 4 zur Abstandsmessung mittels HC-SR04 oder VL53L0X, umgesetzt in C++ mit einem lokalen Webinterface über WLAN.

## 🔧 Funktionen
- C++-basierte Sensorabfrage (HC-SR04, VL53L0X)
- Lokales Webinterface (HTML/JavaScript) zur Anzeige der Entfernung
- WLAN-Kommunikation über einfachen Webserver

## 🖥️ Voraussetzungen
- Raspberry Pi 4 mit Raspberry Pi OS
- wiringPi installiert
- G++ und CMake

## 🚀 Kompilierung
```bash
mkdir build && cd build
cmake ..
make
```

## 🌐 Webinterface starten
```bash
./MiniParkassistent
```
Dann im Browser öffnen: `http://<Raspberry_Pi_IP>:8080`
```bash
http://<Raspberry_Pi_IP>:8080
```
## 🪛 Hardware
- Raspberry Pi 4
- HC-SR04 oder VL53L0X Sensor
- LED Rot, LED Gelb, LED Grün
- Buzzer
- Widerständen
- Jumper-Kabel

## 📐 Text-Schaltplan für Raspberry Pi 4 GPIO-Verbindungen
```
[Raspberry Pi 4 GPIO-Pins]

                          HC-SR04
                    +------------------+
VCC (5V, Pin 2) ----| VCC              |
GND (Pin 6) --------| GND              |
GPIO23 (Pin 16) ----| TRIG             |
                    | ECHO             |----+
                    +------------------+    |
                                            |
                                          [1 kΩ]
                                            |
                                            +----> GPIO24 (Pin 18)
                                            |
                                          [2 kΩ]
                                            |
                                           GND (Pin 14)

                          LEDs (über 330 Ω)
                          ------------------

GPIO17 (Pin 11) ----[330 Ω]----->|---- Breadboard GND-Leiste  (LED Rot)
GPIO27 (Pin 13) ----[330 Ω]----->|---- Breadboard GND-Leiste  (LED Gelb)
GPIO22 (Pin 15) ----[330 Ω]----->|---- Breadboard GND-Leiste  (LED Grün)

                          Buzzer (passiv)
                          ----------------

GPIO18 (Pin 12) -----------------> (+)Buzzer(-) ---- GND (Pin 9)

```

## 🎥 Demo-Video

[!Watch the video](https://youtu.be/yX5S4pld-jY)

