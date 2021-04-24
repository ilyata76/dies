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
	if (a.CheckDate() && b.CheckDate()) {
		dies result = { 1, 1, 1 };
		int Y = INT_CHECK, M = INT_CHECK, D = INT_CHECK;
		if (b < a) { dies temp{ 1,1,1 }; temp = a; a = b; b = temp; };

		if (a.getYear() != b.getYear()) {
			Y = int_rand_result(a.getYear(), b.getYear());

			if (Y == a.getYear()) {
				// год на первый

				M = int_rand_result(a.getMonth(), 12);
				
				if (M == a.getMonth()) {
					if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
						D = int_rand_result(a.getDay(), 31);
					} else if (M == 4 || M == 6 || M == 9 || M == 11) {
						D = int_rand_result(a.getDay(), 30);
					} else if (M == 2 && LeapYear(Y)) {
						D = int_rand_result(a.getDay(), 29);
					} else if (M == 2 && !LeapYear(Y)) {
						D = int_rand_result(a.getDay(), 28);
					} //else return
				} else {
					if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
						D = int_rand_result(1, 31);
					} else if (M == 4 || M == 6 || M == 9 || M == 11) {
						D = int_rand_result(1, 30);
					} else if (M == 2 && LeapYear(Y)) {
						D = int_rand_result(1, 29);
					} else if (M == 2 && !LeapYear(Y)) {
						D = int_rand_result(1, 28);
					} //else return
				}
			} else if (Y == b.getYear()) {
				M = int_rand_result(1, b.getMonth());

				if (M == b.getMonth()) {
					D = int_rand_result(1, b.getDay());
				} else {
					if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
						D = int_rand_result(1, 31);
					} else if (M == 4 || M == 6 || M == 9 || M == 11) {
						D = int_rand_result(1, 30);
					} else if (M == 2 && LeapYear(Y)) {
						D = int_rand_result(1, 29);
					} else if (M == 2 && !LeapYear(Y)) {
						D = int_rand_result(1, 28);
					} // else return
				}

			} else if (Y != b.getYear() && Y != a.getYear()){
				M = int_rand_result(1, 12);

				if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
					D = int_rand_result(1, 31);
				} else if (M == 4 || M == 6 || M == 9 || M == 11) {
					D = int_rand_result(1, 30);
				} else if (M == 2 && LeapYear(Y)) {
					D = int_rand_result(1, 29);
				} else if (M == 2 && !LeapYear(Y)) {
					D = int_rand_result(1, 28);
				} // else return
			}

		} else if (a.getYear() == b.getYear()) {
			if (a == b) return a;

			Y = a.getYear();

			if (a.getMonth() != b.getMonth()) {

				M = int_rand_result(a.getMonth(), b.getMonth());

				if (M == a.getMonth()) {
					if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
						D = int_rand_result(a.getDay(), 31);
					} else if (M == 4 || M == 6 || M == 9 || M == 11) {
						D = int_rand_result(a.getDay(), 30);
					} else if (M == 2 && LeapYear(Y)) {
						D = int_rand_result(a.getDay(), 29);
					} else if (M == 2 && !LeapYear(Y)) {
						D = int_rand_result(a.getDay(), 28);
					}
				} else if (M == b.getMonth()) {
					D = int_rand_result(1, b.getDay());
				} else {
					if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
						D = int_rand_result(1, 31);
					} else if (M == 4 || M == 6 || M == 9 || M == 11) {
						D = int_rand_result(1, 30);
					} else if (M == 2 && LeapYear(Y)) {
						D = int_rand_result(1, 29);
					} else if (M == 2 && !LeapYear(Y)) {
						D = int_rand_result(1, 28);
					}
				}
			} else {
				M = a.getMonth();
				D = int_rand_result(a.getDay(), b.getDay());
			}
		}

		result.input(Y, M, D);
		return result;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "a.CheckDate() == " << a.CheckDate() << "; b.CheckDate() == " << b.CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}