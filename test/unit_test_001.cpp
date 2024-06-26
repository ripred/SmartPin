//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2023-06-28
// PURPOSE: unit tests for Smooth library
//          https://github.com/RobTillaart/SIMON
//


// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)


#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "SmartPin.h"


unittest_setup()
{
  fprintf(stderr, "Arduino SmartPin library\n");
}


unittest_teardown()
{
}


unittest(test_constructor)
{
  // assertEqual(42, sm.get_window());
  // assertEqual(0, sm.get_count());
  // assertEqualFloat(0, sm.get_avg(), 0.0001);

  // Smooth sm0(5, 0, 0);
  // assertEqual(5, sm0.get_window());
  // assertEqual(0, sm0.get_count());
  // assertEqualFloat(0, sm0.get_avg(), 0.0001);

  // Smooth sm1(7, 20);
  // assertEqual(7, sm1.get_window());
  // assertEqual(20, sm1.get_count());
  // assertEqualFloat(0, sm0.get_avg(), 0.0001);

  // Smooth sm2(15, 25, 10);
  // assertEqual(15, sm2.get_window());
  // assertEqual(25, sm2.get_count());
  // assertEqualFloat(10, sm2.get_avg(), 0.0001);
}


unittest_main()


//  -- END OF FILE --

