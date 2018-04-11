///
/// @file   count_quadruplets.cpp
/// @brief  Count prime quadruplets inside [10^12, 10^12 + 10^9].
///
/// Copyright (C) 2017 Kim Walisch, <kim.walisch@gmail.com>
///
/// This file is distributed under the BSD License. See the COPYING
/// file in the top level directory.
///

#include <primesieve.hpp>

#include <stdint.h>
#include <iostream>
#include <cstdlib>

using namespace std;

void check(bool OK)
{
  cout << "   " << (OK ? "OK" : "ERROR") << "\n";
  if (!OK)
    exit(1);
}

int main()
{
  uint64_t start = (uint64_t) 1e12;
  uint64_t stop = (uint64_t)(1e12 + 1e9);
  uint64_t count = primesieve::count_quadruplets(start, stop);
  cout << "Prime quadruplets inside [10^12, 10^12 + 10^9] = " << count;
  check(count == 7171);

  cout << endl;
  cout << "Test passed successfully!" << endl;

  return 0;
}