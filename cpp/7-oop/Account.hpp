#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_

#include <string>

class Account
{
private:
  double balance = 0;
  std::string name;

public:
  double get_balance();
  void set_balance(double balance);

  std::string get_name();
  void set_name(const std::string &name);

  bool deposit(double amount);
  bool withdraw(double amount);
};

#endif