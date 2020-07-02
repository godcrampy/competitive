#ifndef _UTIL_HPP_
#define _UTIL_HPP_

int number_of_times(long a, long b) {
  if (b <= ((a - 1) / 2)) return 1;
  return -1;
}

#endif