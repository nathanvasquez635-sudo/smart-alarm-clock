# Arduino Smart Alarm Clock

An embedded C++ smart alarm clock built with Arduino, featuring real-time tracking, custom menu control, and standing-detection alarm shutoff logic using an ultrasonic distance sensor.

## Hardware Components
- **Microcontroller:** Arduino (Uno / Nano)
- **RTC Module:** DS3231 (I2C)
- **Display:** LCD Screen (16x2 / I2C)
- **Input:** Rotary Encoder (with push button)
- **Alert:** Piezo Buzzer
- **Distance Sensor:** HC-SR04 Ultrasonic Sensor

## Key Features
- **State Machine Architecture:** Non-blocking C++ state machine for UI navigation and alarm handling.
- **Standing Shutoff Logic:** Requires the user to stand up (detected via HC-SR04 distance measurement) to turn off the alarm.
- **Precise Timekeeping:** Accurately tracks time and date via DS3231 real-time clock.

## Getting Started
1. Open `smart_alarm.ino` in the Arduino IDE.
2. Install required libraries (`RTClib`, `LiquidCrystal_I2C`, etc.).
3. Select your Arduino board and COM port, then click **Upload**.
