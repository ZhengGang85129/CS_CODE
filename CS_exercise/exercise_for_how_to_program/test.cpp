#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ostream>

#include <cstdint>
constexpr int sq(int n)
{
  return n * n;
}
int main()
{
  constexpr int N = 123;
  constexpr int N_SQ = sq(N);
  printf("%d %d\n", N, N_SQ);
}


