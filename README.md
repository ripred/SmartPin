
[![Arduino CI](https://github.com/ripred/SmartPin/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/ripred/SmartPin/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/ripred/SmartPin/actions/workflows/arduino-lint.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/ripred/SmartPin/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/ripred/SmartPin.svg?maxAge=3600)](https://github.com/ripred/SmartPin/releases)


# Arduino SmartPin Library



### Example

```cpp
/*
 * SmartPin.ino
 * 
 * Experimenting with the idea of an object-oriented pin class
 * that uses operator overloading to intuitively abbreviate the 
 * usage of digitalRead(...), digitalWrite(...), analogRead(...)
 * and analogWrite(...)
 * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 * example 1
 * 
 *    SmartPin button(2, INPUT_PULLUP);
 *    SmartPin led(3, OUTPUT);
 * 
 *    while (true) {
 *        led = button;
 *        ...
 *    }
 * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 * 
 * example 2
 * 
 *    SmartPin potentiometer(A0, INPUT, analogWrite, analogRead);
 *    SmartPin led(3, OUTPUT);
 * 
 *    while (true) {
 *        led = potentiometer / 4;
 *        ...
 *    }
 * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 * 
 */
#include <SmartPin.h>

enum MagicNumbers {
    // project-specific pin usage; Change as needed
    BUTTON_PIN =  2,        // a digital input pin wth a push button
    POT_PIN    = A0,        // an analog input pin with a potentiometer
    LED1_PIN   =  3,        // a digital output to follow the button
    LED2_PIN   =  5,        // an analog output to follow the potentiometer

};  // enum MagicNumbers

// a push button that drives an LED
SmartPin  const button_pin(BUTTON_PIN, INPUT_PULLUP);
SmartPin  led1_pin(LED1_PIN, OUTPUT, analogWrite);

// a potentiometer that drives the brightness of an LED
SmartPin  const pot_pin(POT_PIN, INPUT, analogWrite, analogRead);
SmartPin  led2_pin(LED2_PIN, OUTPUT, analogWrite);

inline int invert(int value) { return !value; }

void setup()
{
    auto output = [](SmartPin & sp, int value) { sp = value; delay(4); };

    // example of simple integer assignment
    for (int i=0; i < 4; i++) {
      
        for (int pwm=0; pwm < 256; pwm += 4) output(led1_pin, pwm);
        for (int pwm=255; pwm >= 0; pwm -= 4) output(led1_pin, pwm);
    }

    led1_pin.out_func = digitalWrite;
}

void loop()
{
    led1_pin = !button_pin;   // we invert the HIGH/LOW button value since the button is active-low
    led2_pin = pot_pin / 4;
}
```
