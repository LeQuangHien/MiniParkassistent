# 🚗 Mini Parkassistent mit Raspberry Pi, C++ und Webinterface

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
- HC-SR04 oder VL53L0X Sensor
- Raspberry Pi 4
- Jumper-Kabel
