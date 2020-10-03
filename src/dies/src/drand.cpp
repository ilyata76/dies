#include "../drand.hpp"

int int_rand_result(int a, int b) {
	std::random_device rd;
	std::mt19937 mt(rd());
	if (a > b) {
		int temp = a; a = b; b = temp;
	}
	std::uniform_int_distribution <int> dist(a, b);
	return dist(mt);
}

float float_rand_result(float a, float b) {
	std::random_device rd;
	std::mt19937 mt(rd());
	if (a > b) {
		float temp = a; a = b; b = temp;
	}
	std::uniform_real_distribution <float> dist(a, b);
	return dist(mt);
}

dies drand(dies a = { 1,1,1 }, dies b = { 1,1,1 }) {
	dies result = { 1, 1, 1 };

	if (b < a) { dies temp{ 1,1,1 }; temp = a; a = b; b = temp; };
	return result;
}