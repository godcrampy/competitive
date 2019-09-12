#ifndef _PLAYER
#define _PLAYER

#include <string>
#include <vector>
#include <iostream>

class Player
{
public:
  std::string name;
  int health = 100;
  float xp = 0;

  void talk(std::string text_to_say)
  {
    std::cout << text_to_say << std::endl;
  }
  bool is_dead();
};

#endif