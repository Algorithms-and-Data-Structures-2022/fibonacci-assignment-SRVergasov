#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t
#include <iostream>

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    double u = ((pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n))/(pow(2, n) * sqrt(5)));

    return static_cast<int64_t>(round(u));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;
    for (int i = 2; i <= n; ++i) {
      int next = fib_prev + fib_curr;
      fib_prev = fib_curr;
      fib_curr = next;
    }
    return fib_curr;
  }

  int64_t fib_recursive(int n) {

    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }

    cache[0] = 0;
    cache[1] = 1;

    for (int i = 2; i <= n; ++i) {
      cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    return matrix_power(FibMatrix, n)[0][1];
  }

}  // namespace assignment
