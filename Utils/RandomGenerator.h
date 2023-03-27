#pragma once
#include "Common.h"
#include<set>
#include<vector>
#include<cmath>

void srand_64(long a);

uint64_t rand_64();

uint32_t rand_32();

uint16_t rand_16();

uint8_t rand_8();


std::vector<uint32_t> randomVector(int vectorSize, int totalSize);

std::set<uint32_t> randomSet(int vectorSize, int totalSize);

template<uint32_t N>
std::bitset<N> randomBitset() {
	std::bitset<N> res = 0;
	int btIndx;
	for (auto i = 0; i < ceil((double)N / 64); ++i) {
		uint64_t local64 = rand_64();
		btIndx = 64 * i;
		int msb = btIndx + 64 > N ? (N % 64) : 64;
		for (auto bt = 0; bt < msb; ++bt) {
			if (bit64(local64, bt) == 1) {
				res.flip(btIndx+bt);
			}
		}
	}
	return res;
}
