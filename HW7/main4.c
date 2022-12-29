#include <stdio.h>

int main(void)
{
  int i = 12345;
  int thousand = i / 1000 % 10;
  int ones = i % 10;
  int j = (i) - (thousand * 1000) + (ones * 1000) - (ones) + (thousand);
  printf("%d -> %d\n", i, j);
  return 0;
}

