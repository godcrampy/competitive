#ifndef _PLAYER
#define _PLAYER

#include <iostream>
#include <string>
#include <vector>

class Player {
 private:
  std::string name;
  int health;
  float xp;

 public:
  Player(std::string name = "", int health = 80, float xp = 10.0);
  Player(const Player &source);
  ~Player();
  void print_player();
  std::string get_name() { return name; }
  int get_health() { return health; }
  float get_xp() { return xp; }
};

#endif