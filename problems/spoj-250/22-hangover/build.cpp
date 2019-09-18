#include <iostream>

int number_of_cards(float length)
{
  int i = 2;
  float current_length = 0;
  while (current_length < length)
  {
    current_length += 1 / static_cast<float>(i);
    ++i;
  }
  return i - 2;
}

int main()
{
  float n;
  while (true)
  {
    std::cin >> n;
    if (n == 0.00)
      break;
    std::cout << number_of_cards(n) << " card(s)" << std::endl;
  }
  return 0;
}
