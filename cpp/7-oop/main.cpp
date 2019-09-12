#include <iostream>
#include "Player.h"

void fun_foo(Player player)
{
  // do nothing!
}

int main(int argc, char const *argv[])
{
  Player mario("Mario");
  mario.print_player();

  Player samuel_umtiti("Umtiti");
  samuel_umtiti.print_player();

  Player messi("Messi", 1000, 45);
  messi.print_player();

  Player ronaldo(messi);
  ronaldo.print_player();

  fun_foo(samuel_umtiti);

  return 0;
}
