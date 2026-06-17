# Arduino SmartPin Library

[![Arduino CI](https://img.shields.io/static/v1?style=flat&label=Arduino+CI&message=passing&color=2da44e&labelColor=24292f)](https://github.com/ripred/SmartPin/actions/workflows/arduino_test_runner.yml)
[![Arduino-lint](https://img.shields.io/static/v1?style=flat&label=Arduino-lint&message=passing&color=2da44e&labelColor=24292f)](https://github.com/ripred/SmartPin/actions/workflows/arduino-lint.yml)
[![JSON check](https://img.shields.io/static/v1?style=flat&label=JSON+check&message=passing&color=2da44e&labelColor=24292f)](https://github.com/ripred/SmartPin/actions/workflows/jsoncheck.yml)
[![Arduino Library Manager](https://img.shields.io/static/v1?style=flat&label=Arduino+Library+Manager&message=available&color=00878f&labelColor=24292f)](https://www.ardu-badge.com/SmartPin)
[![Release](https://img.shields.io/static/v1?style=flat&label=Release&message=SmartPin_V1&color=8250df&labelColor=24292f)](https://github.com/ripred/SmartPin/releases/latest)
[![License](https://img.shields.io/static/v1?style=flat&label=License&message=MIT&color=0969da&labelColor=24292f)](https://github.com/ripred/SmartPin/blob/main/LICENSE)
[![Stars](https://img.shields.io/static/v1?style=flat&label=Stars&message=2&color=bf8700&labelColor=24292f)](https://github.com/ripred/SmartPin/stargazers)
[![Forks](https://img.shields.io/static/v1?style=flat&label=Forks&message=0&color=6f42c1&labelColor=24292f)](https://github.com/ripred/SmartPin/network/members)

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
 *    void loop() {
 *        led = !button;
 *        ...
 *    }
 * 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 * 
 * example 2
 * 
 *    SmartPin potentiometer(A0, INPUT, analogWrite, analogRead);
 *    SmartPin led(3, OUTPUT, analogWrite);
 * 
 *    void loop() {
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
    LED1_PIN   =  3,        // a digital output pin to follow the button
    LED2_PIN   =  5,        // a pwm output pin to follow the potentiometer value

};  // enum MagicNumbers

// a push button that drives an LED
SmartPin  button_pin(BUTTON_PIN, INPUT_PULLUP);
SmartPin  led1_pin(LED1_PIN, OUTPUT);

// a potentiometer that drives the PWM brightness of an LED
SmartPin  pot_pin(POT_PIN, INPUT, analogWrite, analogRead);
SmartPin  led2_pin(LED2_PIN, OUTPUT, analogWrite);

void setup()
{
    // example LED fade in/out using simple integer assignment
    for (int i=0; i < 4; i++) {
        for (int pwm=0; pwm < 256; pwm += 4) {
            led2_pin = pwm;
            delay(4);
        }
        for (int pwm=255; pwm >= 0; pwm -= 4) {
            led2_pin = pwm;
            delay(4);
        }
    }
}

void loop()
{
    // using the pins is ridiculously easy 😎:
    led1_pin = !button_pin;   // we invert the HIGH/LOW value since the button is active-low
    led2_pin = pot_pin / 4;   // set the led brightness relative to the potentiometer value
}
```
