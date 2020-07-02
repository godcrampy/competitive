#include "ComplexNumber.hpp"

#include <iostream>

ComplexNumber::ComplexNumber(int real, int complex)
    : real{real}, complex{complex} {}

int ComplexNumber::get_real_part() { return this->real; }

void ComplexNumber::set_real_part(int real) { this->real = real; }

int ComplexNumber::get_complex_part() const { return this->complex; }

void ComplexNumber::set_complex_part(int complex) { this->complex = complex; }
