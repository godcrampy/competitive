#include <iostream>

#include "ComplexNumber.hpp"
ComplexNumber addNumber(ComplexNumber a, ComplexNumber b) {
  return ComplexNumber(a.real + b.real, a.complex + b.complex);
}
int main(int argc, char const *argv[]) {
  ComplexNumber a(1, 4);
  ComplexNumber b(4, 6);
  a.print_number();
  b.print_number();
  ComplexNumber c = addNumber(a, b);
  c.print_number();
  return 0;
}
