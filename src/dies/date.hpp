#pragma once

	#include <iostream>
	#include <iomanip>

#ifndef DATE_HPP
#define DATE_HPP

	//system("chcp 65001");

		#define INT_CHECK 6666


	// dies.LeapYear() -> bool
	// dies.YearMonthDayCheck() -> bool -> проверка сформировался ли класс -> if d/m/y == int_check return false
	// getday getmon gety
	// CheckDate( везде везде использовать	


		bool YearMonthDayCheck(int Y, int M, int D);
		bool LeapYear(int Y);


	class dies {
	protected:
		int DD{}, MM{}, YYYY{};
	public:
		dies() { DD = INT_CHECK; MM = INT_CHECK; YYYY = INT_CHECK; };
		dies(int x) {
			if (YearMonthDayCheck(x, x, x)) {
				DD = x; MM = x; YYYY = x;
			} else {
				DD = INT_CHECK; MM = INT_CHECK; YYYY = INT_CHECK;
			}
		};
		dies(int Y, int M, int D) {
			if (YearMonthDayCheck(Y, M, D)) {
				DD = D; MM = M; YYYY = Y;
			} else {
				DD = INT_CHECK; MM = INT_CHECK; YYYY = INT_CHECK;
			}
		};

		dies& input(int Y, int M, int D);

		bool CheckDate();

		friend bool operator > (dies& a, dies& b);
		friend bool operator >= (dies& a, dies& b);
		friend bool operator < (dies& a, dies& b);
		friend bool operator <= (dies& a, dies& b);
		friend bool operator == (dies& a, dies& b);

		friend std::istream& operator >> (std::istream& in, dies& X);
		friend std::ostream& operator << (std::ostream& out, dies& X);

		friend int operator - (dies a, dies b);

		dies operator - (int X);
		dies operator + (int X);
		dies operator = (dies& X);

		friend dies operator ++ (dies &X);
		friend dies operator -- (dies &X);
		friend dies operator -- (dies &X, int);
		friend dies operator ++ (dies &X, int);

		dies operator += (int X);
		dies operator -= (int X);


		int getDay() {
			return this->DD;
		}
		int getMonth() {
			return this->MM;
		}
		int getYear() {
			return this->YYYY;
		}

		~dies() { };
	};

#endif // !DATE_HPP