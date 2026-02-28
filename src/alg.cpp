// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value <= 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;
  for (uint64_t i = 5; i <= value / i; i += 6) {
      if (value % i == 0 || value % (i + 2) == 0)
          return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  uint64_t count = 0;
  uint64_t current = 2;
  while (true) {
      if (checkPrime(current)) {
          count++;
          if (count == n) return current;
      }
      current++;
  }
  return 2;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;
  
  uint64_t candid = value + 1;
  if (candid > 2 && candid % 2 == 0) {
      candid++;
  }

  while (!checkPrime(candid)) {
      candid += 2;
  }
  return candid;
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  if (hbound <= 2) return 0;
  
  for (uint64_t i = 2; i < hbound; ++i) {
      if (checkPrime(i)) {
          sum += i;
      }
  }
  return sum;
  return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  
  if (hbound <= lbound + 2) return 0;

  for (uint64_t p = lbound; p + 2 < hbound; ++p) {
      if (checkPrime(p) && checkPrime(p + 2)) {
          count++;
      }
  }
  return count;
  return 1;
}
