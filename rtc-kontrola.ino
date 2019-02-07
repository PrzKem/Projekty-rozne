//oznaczenia: H-godzina; M-minuta; S-sekunda

#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;
boolean state = LOW;
//uzupelniasz numer pinu wyjsciowego
const int pinWyjsciowy = ;
//czas w ktorym zalaczasz element wykonawczy
const int Hon=;
const int Mon=;
const int Son=;
//czas w ktorym wylaczasz element wykonawczy
const int Hoff=;
const int Moff=;
const int Soff=;

void setup() {
  Serial.begin(9600);
  pinMode(pinWyjsciowy, OUTPUT);
  digitalWrite(pinWyjsciowy, state);
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // ustawienia poczatkowe daty i czasu
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop() {
 DateTime now = rtc.now();
 if((now.hour()==Hon)&&(now.minute()==Mon)&&(now.second()==Son))
    state = HIGH;
 else if((now.hour()==Hoff)&&(now.minute()==Moff)&&(now.second()==Soff))
    state = LOW;
 digitalWrite(pinWyjsciowy, state)
}
