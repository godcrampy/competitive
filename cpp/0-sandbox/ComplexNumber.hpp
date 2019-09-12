#ifndef _COMPLEX_NUMBER_HPP_
#define _COMPLEX_NUMBER_HPP_
#include <iostream>

class ComplexNumber
{
private:
  int real;
  int complex;

public:
  friend ComplexNumber addNumber(ComplexNumber, ComplexNumber);
  ComplexNumber(int real = 0, int complex = 0);
  int get_real_part();
  void set_real_part(int real);

  int get_complex_part() const;
  void set_complex_part(int complex);

  void print_number();
};

inline void ComplexNumber::print_number()
{
  std::cout << this->real << " + " << this->complex << "i" << std::endl;
}
#endif