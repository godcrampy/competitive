#include "Account.hpp"
#include <iostream>

double Account::get_balance() {
  return balance;
}

void Account::set_balance(double balance) {
  this->balance = balance;
}

std::string Account::get_name() {
  return this->name;
}

void Account::set_name(const std::string &name) {
  this->name = name;
}

bool Account::deposit(double amount) {
  if (amount > 10000) {
    std::cout << "Do KYC!" << std::endl;
    return false;
  }
  this->balance += amount;
  std::cout << "Deposited! Current Balance: " << get_balance() << std::endl;
  return true;
}

bool Account::withdraw(double amount) {
  if (amount > this->balance) {
    std::cout << "Not enough funds" << std::endl;
    return false;
  }
  this->balance -= amount;
  std::cout << "Withdrawen! Current Balance: " << get_balance() << std::endl;
  return true;
}