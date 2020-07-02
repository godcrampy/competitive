#include "Player.h"

Player::Player(std::string name, int health, float xp) : name{name}, health{100}, xp{xp} {
  this->health = health < 100 ? health : 100;
}

Player::Player(const Player &source) : Player(source.name, source.health, source.xp / 2) {
  std::cout << "Copy Constructor called" << std::endl;
}

void Player::print_player() {
  std::cout << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Health: " << this->health << std::endl;
  std::cout << "XP: " << this->xp << std::endl;
}

Player::~Player() {
  std::cout << this->name << " Destroyed" << std::endl;
}