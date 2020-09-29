#pragma once

#ifndef BASE_H
	#define BASE_H

	#include <iostream>
	#include <iomanip>
#endif // !BASE_H




	#define INT_CHECK 6666


// dies.leapyear() -> bool
// dies.check() -> bool -> проверка сформировался ли класс -> if d/m/y == int_check return false
// getday getmon gety
// CHECK везде везде использовать	


	bool check(int Y, int M, int D);
	bool leapyear(int Y);


class dies {
private:
	int DD{}, MM{}, YYYY{};
public:
	dies() { DD = INT_CHECK; MM = INT_CHECK; YYYY = INT_CHECK; };
	dies(int x) {
		if (check(x, x, x)) {
			DD = x; MM = x; YYYY = x;
		} else {
			DD = INT_CHECK; MM = INT_CHECK; YYYY = INT_CHECK;
		}
	};
	dies(int Y, int M, int D) {
		if (check(Y, M, D)) {
			DD = D; MM = M; YYYY = Y;
		} else {
			DD = INT_CHECK; MM = INT_CHECK; YYYY = INT_CHECK;
		}
	};

	dies& input(int Y, int M, int D);

	bool CHECK();

	friend bool operator > (dies& a, dies& b);
	friend bool operator >= (dies& a, dies& b);
	friend bool operator < (dies& a, dies& b);
	friend bool operator <= (dies& a, dies& b);
	friend bool operator == (dies& a, dies& b);

};


