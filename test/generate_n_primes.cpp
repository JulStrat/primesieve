///
/// @file   generate_n_primes.cpp
/// @brief  Test n prime number generation
///
/// Copyright (C) 2017 Kim Walisch, <kim.walisch@gmail.com>
///
/// This file is distributed under the BSD License. See the COPYING
/// file in the top level directory.
///

#include <primesieve.hpp>

#include <stdint.h>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

using namespace std;
using namespace primesieve;

// primes inside [0, 100]
const uint64_t small_primes[25] =
{
   2,  3,  5,  7, 11,
  13, 17, 19, 23, 29,
  31, 37, 41, 43, 47,
  53, 59, 61, 67, 71,
  73, 79, 83, 89, 97
};

// primes inside [18446744073709550681, 18446744073709551533]
const uint64_t large_primes[19] =
{
  18446744073709550681ull,
  18446744073709550717ull,
  18446744073709550719ull,
  18446744073709550771ull,
  18446744073709550773ull,
  18446744073709550791ull,
  18446744073709550873ull,
  18446744073709551113ull,
  18446744073709551163ull,
  18446744073709551191ull,
  18446744073709551253ull,
  18446744073709551263ull,
  18446744073709551293ull,
  18446744073709551337ull,
  18446744073709551359ull,
  18446744073709551427ull,
  18446744073709551437ull,
  18446744073709551521ull,
  18446744073709551533ull
};

void check(bool isCorrect)
{
  cout << "   " << (isCorrect ? "OK" : "ERROR") << "\n";
  if (!isCorrect)
    throw runtime_error("test failed!");
}

int main()
{
  try
  {
    vector<uint64_t> primes;
    generate_n_primes(25, &primes);
    cout << "primes.size() = " << primes.size();
    check(primes.size() == 25);

    for (uint64_t i = 0; i < primes.size(); i++)
    {
      cout << "primes[" << i << "] = " << primes[i];
      check(primes[i] == small_primes[i]);
    }

    primes.clear();
    generate_n_primes(19, 18446744073709550672ull, &primes);
    cout << "primes.size() = " << primes.size();
    check(primes.size() == 19);

    for (uint64_t i = 0; i < primes.size(); i++)
    {
      cout << "primes[" << i << "] = " << primes[i];
      check(primes[i] == large_primes[i]);
    }
  }
  catch (exception& e)
  {
    cerr << endl;
    cerr << "Error: " << e.what() << endl;
    return 1;
  }

  cout << endl;
  cout << "All tests passed successfully!" << endl;

  return 0;
}
