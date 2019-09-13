#ifndef _BIG_INT_HPP_
#define _BIG_INT_HPP_
#include <string>
#include <vector>
#include <iostream>

/**================================================== *
 * ==========  Big Integer Class  =================== *
 * ================================================== */
/**
 *
 * * A Custom made class for doing arithmetic and comparisions of very
 * * large numbers in C++
 * 
 * ! Not Complete
 * Current Implementation provides the following operations:
 * 1. BigInt ? BigInt: addition, subtraction
 * 2. BigInt ? Integer: division
 * 
 * ? private member string will store 541 as "541",
 * ? private member number will store 541 as [1, 4, 5, 0, 0 ,...]
 * ? private member size is vector number
 * 
 * Although vectors are dynamic, the private member number will stay of the same size,
 * this was done to reduce implementation complexity of various operations. This also
 * gives added benefit of vector not being re-allocated internally to fit additional
 * integers thus reducing compute time at the cost of some space in memory.
 */

class BigInteger
{
private:
  std::string string;
  std::vector<int> number;
  int size;

public:
  BigInteger(std::string = "", int = 200);
  std::string get_string() { return this->string; }
  std::vector<int> get_number() { return this->number; }
  void set_string(std::string);
  void string_to_integer();
  void integer_to_string();
  int get_MSB_position();
  BigInteger operator+(const BigInteger &object);
  BigInteger operator-(const BigInteger &object);
  BigInteger operator/(const int integer);
};

BigInteger::BigInteger(std::string string, int size) : string{string}, number{std::vector<int>(size, 0)}, size{size}
{
  this->string_to_integer();
}

void BigInteger::set_string(std::string string)
{
  this->string = string;
}

int BigInteger::get_MSB_position()
{
  int first_place = 0;
  for (int i = 0; i < this->size; i++)
    if (this->number.at(i) != 0)
      first_place = i;
  return first_place;
}

void BigInteger::string_to_integer()
{
  // works
  int length_of_string = this->string.length();
  for (int i = 0; i < length_of_string; ++i)
    this->number.at(i) = string.at(length_of_string - i - 1) - '0';
}

void BigInteger::integer_to_string()
{
  // works
  int first_place = get_MSB_position(); // position of MSB
  this->string = "";
  for (int i = first_place; i >= 0; --i)
    this->string.push_back(static_cast<char>(this->number.at(i) + '0'));
}

BigInteger BigInteger::operator+(const BigInteger &object)
{
  // works
  BigInteger final;
  int carry = 0, sum = 0;
  for (int i = 0; i < this->size; i++)
  {
    sum = this->number.at(i) + object.number.at(i) + carry;
    final.number.at(i) = sum % 10;
    carry = sum / 10;
  }
  final.integer_to_string();
  return final;
}

BigInteger BigInteger::operator-(const BigInteger &object)
{
  // Assumption: first number is larger than the second number
  BigInteger final;
  bool borrow = false;
  int a, b;
  for (int i = 0; i < this->size; i++)
  {
    a = this->number.at(i) - borrow;
    b = object.number.at(i);
    if (a >= b)
      borrow = false;
    else
    {
      a += 10;
      borrow = true;
    }
    final.number.at(i) = a - b;
  }
  final.integer_to_string();
  return final;
}

BigInteger BigInteger::operator/(const int integer)
{
  BigInteger final;
  int first_place = get_MSB_position(), a = 0, b = 0;
  int donate = 0;
  for (int i = first_place; i >= 0; --i)
  {
    a = (this->number.at(i) + 10 * donate) / integer;
    b = (this->number.at(i) + 10 * donate) % integer;
    final.number.at(i) = a;
    donate = b;
  }
  final.integer_to_string();
  return final;
}

/* =======  End of Big Integer Class  ======= */

#endif