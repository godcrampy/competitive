#if !defined(_VEHICLE_HPP_)
#define _VEHICLE_HPP_
#include <iostream>
#include <string>

class Vehicle {
 protected:
  int wheels;
  int max_speed;
  std::string sound;

 public:
  Vehicle(int wheels = 4, int max_speed = 100,
          std::string sound = "Vroom Vroom");
  void start();
};

Vehicle::Vehicle(int wheels, int max_speed, std::string sound)
    : wheels(wheels), max_speed(max_speed), sound(sound) {
  std::cout << "New Vehicle!" << std::endl;
}

void Vehicle::start() { std::cout << this->sound << std::endl; }

#endif  // _VEHICLE_HPP_
