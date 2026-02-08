#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "config.h"

// Configure credentials in config.h (copy from config.example.h).
#ifndef FIREBASE_HOST
#error "FIREBASE_HOST is not defined. Update config.h."
#endif
#ifndef FIREBASE_AUTH
#error "FIREBASE_AUTH is not defined. Update config.h."
#endif
#ifndef WIFI_SSID
#error "WIFI_SSID is not defined. Update config.h."
#endif
#ifndef WIFI_PASSWORD
#error "WIFI_PASSWORD is not defined. Update config.h."
#endif

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
  // set value
  //String SpeedFire = String(n)+String("Kmph");
  Firebase.pushInt("Data",n);
  Firebase.setInt ("DataNum",n);
  //String SoCFire = String(n)+String("%");
  Firebase.setInt ("AccumulatorSoC",n);
  //String AccFire = String(n)+String("m/s^2");
  Firebase.setInt ("Acceleration",n);
  //String RangeFire = String(n)+String("Kmph");
  Firebase.setInt ("Range",n);
  
  Serial.print(n);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
delay(1000);
n += 1;
  
// update value
Firebase.setFloat("number", 43.0);
// handle error
if (Firebase.failed()) {
Serial.print("setting /number failed:");
Serial.println(Firebase.error());  
return;
}
delay(1000);

// get value 
Serial.print("number: ");
Serial.println(Firebase.getFloat("number"));
delay(1000);

// remove value
Firebase.remove("number");
delay(1000);

// set string value
Firebase.setString("message", "hello world");
// handle error
if (Firebase.failed()) {
Serial.print("setting /message failed:");
Serial.println(Firebase.error());  
return;
}
delay(1000);

// set bool value
Firebase.setBool("truth", false);
// handle error
if (Firebase.failed()) {
Serial.print("setting /truth failed:");
Serial.println(Firebase.error());  
return;
}
delay(1000);

// append a new value to /logs
String name = Firebase.pushInt("logs", n++);
// handle error
if (Firebase.failed()) {
Serial.print("pushing /logs failed:");
Serial.println(Firebase.error());  
return;
}
Serial.print("pushed: /logs/");
Serial.println(name);
delay(1000);
}
