# Real-time Data Acquisition App

An IoT telemetry data acquisition system that streams sensor values to Firebase in real time, designed to work with an Android client and embedded hardware.

## Overview
- Embedded sketch (`Telemetry_Data.ino`) uses ESP8266 WiFi and Firebase
- Android client app lives on the `master` branch
- Designed for real-time data capture and dashboarding

## Hardware
- ESP8266 (NodeMCU or compatible)
- Sensors as required by your telemetry setup
- WiFi connectivity

## Setup
1. Copy the example config:
   ```bash
   cp config.example.h config.h
   ```
2. Update `config.h` with your Firebase host/auth token and WiFi credentials.
3. Open `Telemetry_Data.ino` in the Arduino IDE and select your ESP8266 board.

## Build & Upload
- Board: `esp8266:esp8266:nodemcuv2` (or your compatible board)
- Upload from Arduino IDE

## Notes
- `config.h` is excluded from git to avoid leaking credentials.
- FirebaseArduino library is required. See CI workflow for installation hints.
