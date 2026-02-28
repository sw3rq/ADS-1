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
  uint64_t result = 2;
  if (n > 0) {
      uint64_t count = 0;
      uint64_t current = 2;
      while (true) {
          if (checkPrime(current)) {
              count++;
              if (count == n) {
                  result = current;
                  break;
              }
          }
          current++;
      }
  }
  return result;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t result = 2;
  if (value < 2) {
      result = 2;
  } else {
      uint64_t candidate = value + 1;
      if (candidate % 2 == 0) {
          candidate++;
      }

      while (!checkPrime(candidate)) {
          candidate += 2;
      }
      result = candidate;
  }
  return result;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t result = 0;
  if (hbound > 2) {
      uint64_t sum = 0;
      for (uint64_t i = 2; i < hbound; ++i) {
          if (checkPrime(i)) {
              sum += i;
          }
      }
      result = sum;
  }
  return result;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t result = 0;
  if (hbound > lbound + 2) {
      uint64_t count = 0;
      for (uint64_t p = lbound; p + 2 < hbound; ++p) {
          if (checkPrime(p) && checkPrime(p + 2)) {
              count++;
          }
      }
      result = count;
  }
  return result;
}
