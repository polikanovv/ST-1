// Copyright 2025 UNN-CS
#include <cstdint>
#include <cmath>
#include <vector>
#include "alg.h"


bool checkPrime(uint64_t value) {
	if (value < 2) return false;
	if (value == 2) return true;
	if ((value & 1ULL) == 0) return false;

	for (uint64_t i = 3; i * i <= value; i += 2) {
		if (value % i == 0)
			return false;
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	if (n == 0) return 0;
	uint64_t count = 0;
	uint64_t candidate = 2;
	while (true) {
		if (checkPrime(candidate)) {
			++count;
			if (count == n)
				return candidate;
		}
		candidate++;
	}
	return 0;
}

uint64_t nextPrime(uint64_t value) {
	uint64_t candidate = value + 1;
	while (true) {
		if (checkPrime(candidate))
			return candidate;
		candidate++;
	}
	return 0;
}

uint64_t sumPrime(uint64_t hbound) {
	if (hbound < 2) return 0;
	std::vector<bool> is_prime(hbound, true);
	is_prime[0] = false;
	if (hbound > 1)
		is_prime[1] = false;
	for (uint64_t i = 2; i * i < hbound; i++) {
		if (is_prime[i]) {
			for (uint64_t j = i * i; j < hbound; j += i)
				is_prime[j] = false;
		}
	}
	uint64_t sum = 0;
	for (uint64_t i = 2; i < hbound; i++) {
		if (is_prime[i])
			sum += i;
	}
	return sum;
}