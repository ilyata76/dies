#include "../calenday.hpp"

std::string calen::nameOfNumber(int N) {
	if (N == 1) return "Monday";
	else if (N == 2) return "Tuesday";
	else if (N == 3) return "Wednesday";
	else if (N == 4) return "Thursday";
	else if (N == 5) return "Friday";
	else if (N == 6) return "Saturday";
	else if (N == 7) return "Sunday";
	else return "ERROR";
}
