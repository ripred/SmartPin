/*
 * SmartPin.h
 * 
 * Experimenting with the idea of an object-oriented pin class
 * that uses operator overloading to intuitively abbreviate the 
 * usage of digitalRead(...), digitalWrite(...), analogRead(...)
 * and analogWrite(...)
 * 
 * 
 * version 1.0 Feb 2024 trent m. wyatt
 * 
 */

#ifndef SMARTPIN_H_INCL
#define SMARTPIN_H_INCL

#include <inttypes.h>

using OutFunc = void (*)(uint8_t, uint8_t);
using InFunc = int (*)(uint8_t);

struct SmartPin {
    int8_t    pin;
    OutFunc   out_func;
    InFunc    in_func;

    SmartPin() = delete;

    SmartPin(
      int8_t const pin,                 // the pin to use
      int8_t const mode,                // the pinMode
      OutFunc ofn = digitalWrite,       // the default output function
      InFunc ifn = digitalRead) :       // the default input function
        pin(pin), 
        out_func(ofn), 
        in_func(ifn)
    {
        pinMode(pin, mode);
    }

    // treat all SmartPin to SmartPin assignments as integer operations
    SmartPin & operator = (SmartPin const &sp)
    {
        return *this = int(sp);
    }

    // write to an output pin when an integer value is assigned to us
    SmartPin & operator = (int const state)
    {
        out_func(pin, state);
        return *this;
    }

    // read from an input pin when we're being coerced into an integer value
    operator int() const 
    {
        return in_func(pin);
    }

};  // struct SmartPin

#endif // SMARTPIN_H_INCL
