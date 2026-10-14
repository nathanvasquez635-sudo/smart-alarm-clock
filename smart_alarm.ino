#include <Wire.h>
#include <LiquidCrystal.h>
#include <RTClib.h>
#include <Encoder.h>

// Initialize the LCD with direct pin wiring: (RS, Enable, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initialize the Real-Time Clock (change to RTC_DS1307 if using DS1307)
RTC_DS3231 rtc;

// Initialize Rotary Encoder on digital pins 9 and 10
Encoder myEnc(9, 10);

// Rotary Encoder Button Pin on digital pin 13
const int encoderButtonPin = 13;

long oldPosition = -999;

void setup() {
  // Configure the encoder push button with internal pull-up
  pinMode(encoderButtonPin, INPUT_PULLUP);
  
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Initialize the RTC module
  if (!rtc.begin()) {
    lcd.setCursor(0, 0);
    lcd.print("RTC Not Found!");
    while (1); // Halt execution if RTC is missing
  }

  // If the RTC lost power, set time to compile time
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.setCursor(0, 0);
  lcd.print("Alarm Clock Ready");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Read rotary encoder position
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.print("Enc: ");
  Serial.println(newPosition);
  }

  // Check if encoder button is pressed
  bool buttonPressed = (digitalRead(encoderButtonPin) == LOW);

  // Read current time from RTC
  DateTime now = rtc.now();

  // Row 0: Display Time (HH:MM:SS)
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  if (now.hour() < 10) lcd.print('0');
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  if (now.minute() < 10) lcd.print('0');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  if (now.second() < 10) lcd.print('0');
  lcd.print(now.second(), DEC);
  lcd.print("   "); // Clear trailing characters

  // Row 1: Display Encoder Position & Button Status
  lcd.setCursor(0, 1);
  lcd.print("Enc:");
  lcd.print(newPosition);
  if (buttonPressed) {
    lcd.print(" [BTN]");
  } else {
    lcd.print("      ");
  }

  delay(100); // Small delay for smooth display updating
}
