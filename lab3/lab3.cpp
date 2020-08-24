/* ASSIGNMENT NAME
 *
 * PROGRAMMER NAME
 * DATE
 */
 #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
 #include "doctest.h"

#include <string>
using std::string;

// COMPLETE EACH OF THE FOLLOWING FUNCTIONS

// Return a greeting: "Nice to meet you, NAME."
// If name param is empty string, return "Nice to meet you."
string greet(string name) {

}

// Return true if denominator is a factor of numerator.
// Return false otherwise.
bool isFactor(int numerator, int denominator) {

}

// Given an initial value, compute how many quarters, dimes, nickels, and
// pennies would be given as change.
void makeChange(unsigned int initialValue, unsigned int &quarters,
                unsigned int &dimes, unsigned int &nickels,
                unsigned int &pennies) {

}

// Convert a Celsius temperature to a Fahrenheit temperature.
double celsiusToFahrenheit(double celsiusTemp) {

}

// Convert a Fahrenheit temperature to a Celsius temperature.
double fahrenheitToCelsius(double fahrenheitTemp) {

}

/*
 * Unit test.
 */

 TEST_CASE("Function implementations") {
   CHECK(greet("") == string("Nice to meet you."));
   CHECK(greet("Jane") == string("Nice to meet you, Jane."));

   CHECK(isFactor(100, 25) == true);
   CHECK(isFactor(100, 24) == false);

   unsigned int quarters, dimes, nickels, pennies;
   makeChange(41, quarters, dimes, nickels, pennies);
   CHECK(quarters == 1);
   CHECK(dimes == 1);
   CHECK(nickels == 1);
   CHECK(pennies == 1);
   makeChange(0, quarters, dimes, nickels, pennies);
   CHECK(quarters == 0);
   CHECK(dimes == 0);
   CHECK(nickels == 0);
   CHECK(pennies == 0);

   CHECK(celsiusToFahrenheit(0.0) == doctest::Approx(32.0));
   CHECK(celsiusToFahrenheit(100.0) == doctest::Approx(212.0));

   CHECK(fahrenheitToCelsius(32.0) == doctest::Approx(0.0));
   CHECK(fahrenheitToCelsius(212.0) == doctest::Approx(100.0));
 }
