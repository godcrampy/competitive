#ifndef _UTIL
#define _UTIL

int numberOfPositions(int largeSize, int smallSize)
{
  return (largeSize - smallSize + 1) * (largeSize - smallSize + 1);
}

int totalPositions(int sizeOfSquare)
{
  int final{};
  for (int i = 1; i <= sizeOfSquare; i++)
    final += numberOfPositions(sizeOfSquare, i);
  return final;
}

#endif