/*
  Blink
  
  Developer: 1234Cyle
  Date: 2.13.2026

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// the setup function runs once when you press reset or power the board
const int speakerPin = 11;
const int fadePin = 3;   // LED that fades

int brightness = 0;
int fadeAmount = 1.9;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {

  // LED State 1
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);

  // Sweep UP
  for (int freq = 500; freq <= 1700; freq += 5) {
    tone(speakerPin, freq);

    // Fade LED on pin 3
    analogWrite(fadePin, brightness);
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    delay(6);
  }

  // LED State 2
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);

  // Sweep DOWN
  for (int freq = 1700; freq >= 500; freq -= 5) {
    tone(speakerPin, freq);

    // Keep fading
    analogWrite(fadePin, brightness);
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    delay(6);
  }
}



