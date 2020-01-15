#ifndef _UTIL
#define _UTIL

bool isAP(int x, int y, int z) {
  return x + z == 2 * y;
}

bool isGP(int x, int y, int z) {
  return x * z == y * y;
}

#endif