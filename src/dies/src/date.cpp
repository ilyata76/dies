#include "../date.hpp"

bool LeapYear(int Y) {
	if (Y % 100 == 0) {
		if (Y % 400 == 0) return true;
		else return false;
	} else {
		if (Y % 4 == 0) return true;
		else return false;
	} return false;
}

bool YearMonthDayCheck(int Y, int M, int D) {
	if (Y <= 0 || D <= 0 || M <= 0 || M > 12 || D > 31 || Y >= INT_CHECK) return false;
		if (M == 1) {
			if (D > 31) return false;
		} else if (M == 2 && LeapYear(Y)) {
			if (D > 29) return false;
		} else if (M == 2 && !LeapYear(Y)) {
			if (D > 28) return false;
		} else if (M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
			if (D > 31) return false;
		} else if (M == 4 || M == 6 || M == 9 || M == 11) {
			if (D > 30) return false;
		} else return false;
		return true;
}

bool dies::CheckDate() {
	if (this->DD == INT_CHECK || 
		this->MM == INT_CHECK || 
		this->YYYY == INT_CHECK) 
			return false;
	else
		return true;
}

dies& dies::input(int Y, int M, int D) {
	if (YearMonthDayCheck(Y, M, D)) {
		DD = D; MM = M; YYYY = Y;
		return *this;
	} else {
		DD = INT_CHECK; MM = INT_CHECK; YYYY = INT_CHECK;
		return *this;
	}
}

bool operator > (dies& a, dies& b) {
	if (a.CheckDate() && b.CheckDate()) {
		if (a.YYYY > b.YYYY) return true;
		else if (a.YYYY < b.YYYY) return false;
		else if (a.YYYY == b.YYYY) {
			if (a.MM > b.MM) return true;
			else if (a.MM < b.MM) return false;
			else if (a.MM == b.MM) {
				if (a.DD > b.DD) return true;
				else if (a.DD < b.DD) return false;
				else if (a.DD == b.DD) return false;
				else return false;
			} else return false;
		} else return false;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "a.CheckDate() == " << a.CheckDate() << "; b.CheckDate() == " << b.CheckDate() << std::endl;
		return false;
	}
}

bool operator >= (dies& a, dies& b) {
	if (a.CheckDate() && b.CheckDate()) {
		if (a.YYYY > b.YYYY) return true;
		else if (a.YYYY < b.YYYY) return false;
		else if (a.YYYY == b.YYYY) {
			if (a.MM > b.MM) return true;
			else if (a.MM < b.MM) return false;
			else if (a.MM == b.MM) {
				if (a.DD > b.DD) return true;
				else if (a.DD < b.DD) return false;
				else if (a.DD == b.DD) return true;
				else return false;
			} else return false;
		} else return false;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "a.CheckDate() == " << a.CheckDate() << "; b.CheckDate() == " << b.CheckDate() << std::endl;
		return false;
	}
}

bool operator < (dies& a, dies& b) {
	if (a.CheckDate() && b.CheckDate()) {
		if (a.YYYY < b.YYYY) return true;
		else if (a.YYYY > b.YYYY) return false;
		else if (a.YYYY == b.YYYY) {
			if (a.MM < b.MM) return true;
			else if (a.MM > b.MM) return false;
			else if (a.MM == b.MM) {
				if (a.DD < b.DD) return true;
				else if (a.DD > b.DD) return false;
				else if (a.DD == b.DD) return false;
				else return false;
			} else return false;
		} else return false;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "a.CheckDate() == " << a.CheckDate() << "; b.CheckDate() == " << b.CheckDate() << std::endl;
		return false;
	}
}

bool operator <= (dies& a, dies& b) {
	if (a.CheckDate() && b.CheckDate()) {
		if (a.YYYY < b.YYYY) return true;
		else if (a.YYYY > b.YYYY) return false;
		else if (a.YYYY == b.YYYY) {
			if (a.MM < b.MM) return true;
			else if (a.MM > b.MM) return false;
			else if (a.MM == b.MM) {
				if (a.DD < b.DD) return true;
				else if (a.DD > b.DD) return false;
				else if (a.DD == b.DD) return true;
				else return false;
			} else return false;
		} else return false;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "a.CheckDate() == " << a.CheckDate() << "; b.CheckDate() == " << b.CheckDate() << std::endl;
		return false;
	}
}

bool operator == (dies& a, dies& b) {
	if (a.CheckDate() && b.CheckDate()) {
		if (a.YYYY == b.YYYY) {
			if (a.MM == b.MM) {
				if (a.DD == b.DD) return true;
				else return false;
			} else return false;
		} else return false;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "a.CheckDate() == " << a.CheckDate() << "; b.CheckDate() == " << b.CheckDate() << std::endl;
		return false;
	}
}

std::ostream& operator << (std::ostream& out, dies& X) {
	if (X.CheckDate()) {
		out
			<< std::setw(4) << std::setfill('0') << X.getYear() << "."
			<< std::setw(2) << std::setfill('0') << X.getMonth() << "."
			<< std::setw(2) << std::setfill('0') << X.getDay();
		return out;
	} else { 
		//system("chcp 65001");
		out 
			/*<< std::boolalpha << "X.CheckDate() == " << X.CheckDate() */
			<< "ERROR";
		return out;
	}
}

std::istream& operator >> (std::istream& in, dies& X) {
	char A = ' '; in >> X.YYYY >> A >> X.MM >> A >> X.DD;
	if (A == '.') {
		if (YearMonthDayCheck(X.YYYY, X.MM, X.DD)) {
			//
		} else {
			X.YYYY = INT_CHECK; X.MM = INT_CHECK; X.DD = INT_CHECK; return in;
		}
	} else {
		X.YYYY = INT_CHECK; X.MM = INT_CHECK; X.DD = INT_CHECK; return in;
	}
	return in;
}

dies dies::operator = (dies& X) {
	if (X.CheckDate()) {
		this->DD = X.DD; this->MM = X.MM; this->YYYY = X.YYYY;
		return *this;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "X.CheckDate() == " << X.CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}

}

dies dies::operator+ (int X) {
	if (this->CheckDate()) {
		int XD = 0; dies result = *this;
		while (true) {
			if (result.MM == 1 || result.MM == 3 || result.MM == 5 || result.MM == 7 || result.MM == 8 || result.MM == 10 || result.MM == 12) {
				if (result.DD + X <= 31) { result.DD = result.DD + X; break; } 
				else if ( result.DD + X == 32) { result.DD = 1; result.MM++; if (result.MM == 13) { result.MM = 1; result.YYYY++; } break; } 
				else { XD = 31 - result.DD; result.DD = 1; result.MM++; X = X - XD - 1; if (result.MM == 13) { result.MM = 1; result.YYYY++; } }
			} else if (result.MM == 4 || result.MM == 6 || result.MM == 9 || result.MM == 11) {
				if (result.DD + X <= 30) { result.DD = result.DD + X; break; } 
				else if (result.DD + X == 31) { result.DD = 1; result.MM++; if (result.MM == 13) { result.MM = 1; result.YYYY++; } break; } 
				else { XD = 30 - result.DD; result.DD = 1; result.MM++; X = X - XD - 1; if (result.MM == 13) { result.MM = 1; result.YYYY++; } }
			} else if (result.MM == 2 && LeapYear(result.YYYY)) {
				if (result.DD + X <= 29) { result.DD = result.DD + X; break; }
				else if (result.DD + X == 30) { result.DD = 1; result.MM++; if (result.MM == 13) { result.MM = 1; result.YYYY++; } break; }
				else { XD = 29 - result.DD; result.DD = 1; result.MM++; X = X - XD - 1; if (result.MM == 13) { result.MM = 1; result.YYYY++; } }
			} else if (result.MM == 2 && !LeapYear(result.YYYY)) {
				if (result.DD + X <= 28) { result.DD = result.DD + X; break; }
				else if (result.DD + X == 29) { result.DD = 1; result.MM++; if (result.MM == 13) { result.MM = 1; result.YYYY++; } break; }
				else { XD = 28 - result.DD; result.DD = 1; result.MM++; X = X - XD - 1; if (result.MM == 13) { result.MM = 1; result.YYYY++; } }
			}
		}
		return result;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "this->CheckDate() == " << this->CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}

dies dies::operator - (int X) {
	if (this->CheckDate()) {
		dies result = *this;
		while (X) {
			result.DD--; X--;
			if (result.DD == 0) {
				if (result.MM == 8 || result.MM == 2 || result.MM == 4 || result.MM == 6 || result.MM == 9 || result.MM == 11) { result.MM--; result.DD = 31; }
				else if (result.MM == 1) { result.MM = 12; result.YYYY--; result.DD = 31; }
				else if (result.MM == 5 || result.MM == 7 || result.MM == 10 || result.MM == 12) { result.MM--; result.DD = 30; }
				else if (result.MM == 3 && LeapYear(result.YYYY)) { result.MM--; result.DD = 29; }
				else if (result.MM == 3 && !LeapYear(result.YYYY)) { result.MM--; result.DD = 28; }
			}
		}
		return result;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "this->CheckDate() == " << this->CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}

int operator - (dies b, dies a) {
	if (b.CheckDate() && a.CheckDate()) {
		int sign = 1;
		if (b < a) { 
			dies temp = { 1, 1, 1 }; 
			temp = a; a = b; 
			b = temp; 
			sign = -1;
		}
		// current day is taken into account
		// in calc
		// last day - not

		int Yr = b.YYYY - a.YYYY; int aM = 0, bM = 0, cM = 0, itM = 0;

		if (Yr) {

			// first month

			if (a.MM == 1 || a.MM == 3 || a.MM == 5 || a.MM == 7 || a.MM == 8 || a.MM == 10 || a.MM == 12) aM += (31 - a.DD);
			else if (a.MM == 2 && LeapYear(a.YYYY)) aM += (29 - a.DD);
			else if (a.MM == 2 && !LeapYear(a.YYYY)) aM += (28 - a.DD);
			else if (a.MM == 4 || a.MM == 6 || a.MM == 9 || a.MM == 11) aM += (30 - a.DD);

			aM++; // current day

			// first year excluding the first month ^

			for (itM = a.MM + 1; itM != 13; itM++) {
				if (itM == 1 || itM == 3 || itM == 5 || itM == 7 || itM == 8 || itM == 10 || itM == 12) aM += 31;
				else if (itM == 2 && LeapYear(a.YYYY)) aM += 29;
				else if (itM == 2 && !LeapYear(a.YYYY)) aM += 28;
				else if (itM == 4 || itM == 6 || itM == 9 || itM == 11) aM += 30;
			}

			// intermediate

			for (int i = 1, Yr = (b.YYYY - a.YYYY + 1) - 2; Yr > 0; Yr--, i++) {
				for (itM = 1; itM != 13; itM++) {
					if (itM == 1 || itM == 3 || itM == 5 || itM == 7 || itM == 8 || itM == 10 || itM == 12) cM += 31;
					else if (itM == 2 && LeapYear(a.YYYY + i)) cM += 29;
					else if (itM == 2 && !LeapYear(a.YYYY + i)) cM += 28;
					else if (itM == 4 || itM == 6 || itM == 9 || itM == 11) cM += 30;
				}
			}

			// the last year 

			if (b.MM != 1) {
				for (itM = 1; itM != b.MM; itM++) {
					if (itM == 1 || itM == 3 || itM == 5 || itM == 7 || itM == 8 || itM == 10 || itM == 12) bM += 31;
					else if (itM == 2 && LeapYear(b.YYYY)) bM += 29;
					else if (itM == 2 && !LeapYear(b.YYYY)) bM += 28;
					else if (itM == 4 || itM == 6 || itM == 9 || itM == 11) bM += 30;
				}
			}
			bM += b.DD - 1;

			//

			return sign * (aM + bM + cM);

		} else if (a.YYYY == b.YYYY && a.MM != b.MM && (a.DD != b.DD || a.DD == b.DD)) {
			if (b.MM != 1) {
				//

				if (a.MM == 1 || a.MM == 3 || a.MM == 5 || a.MM == 7 || a.MM == 8 || a.MM == 10 || a.MM == 12) aM += (31 - a.DD);
				else if (a.MM == 2 && LeapYear(a.YYYY)) aM += (29 - a.DD);
				else if (a.MM == 2 && !LeapYear(a.YYYY)) aM += (28 - a.DD);
				else if (a.MM == 4 || a.MM == 6 || a.MM == 9 || a.MM == 11) aM += (30 - a.DD);
			
				aM++;

				//

				for (itM = a.MM + 1; itM != b.MM; itM++) {
					if (itM == 1 || itM == 3 || itM == 5 || itM == 7 || itM == 8 || itM == 10 || itM == 12) bM += 31;
					else if (itM == 2 && LeapYear(b.YYYY)) bM += 29;
					else if (itM == 2 && !LeapYear(b.YYYY)) bM += 28;
					else if (itM == 4 || itM == 6 || itM == 9 || itM == 11) bM += 30;
				}

				bM += b.DD - 1;

				return sign * (aM + bM);

			}
		} else if (a.YYYY == b.YYYY && a.MM == b.MM && a.DD == b.DD) {
			return sign * 1;
		} else if (a.YYYY == b.YYYY && a.MM == b.MM && a.DD != b.DD) {
			return sign * (b.DD - a.DD);
		} return 0;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "a.CheckDate() == " << a.CheckDate() << "b.CheckDate() == " << b.CheckDate() << std::endl;
		return 0;
	}
}

dies operator++(dies &X) {
	if (X.CheckDate()) {
		return X += 1;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "X.CheckDate() == " << X.CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}

dies operator--(dies &X) {
	if (X.CheckDate()) {
		return X -= 1;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "X.CheckDate() == " << X.CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}

dies operator++(dies& X, int) {
	if (X.CheckDate()) {
		return X += 1;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "X.CheckDate() == " << X.CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}

dies operator--(dies& X, int) {
	if (X.CheckDate()) {
		return X -= 1;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "X.CheckDate() == " << X.CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}

dies dies::operator += (int X) {
	if (this->CheckDate()) {
		*this = *this + X;
		return *this;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "this->CheckDate() == " << this->CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}

dies dies::operator -= (int X) {
	if (this->CheckDate()) {
		*this = *this - X;
		return *this;
	} else {
		//system("chcp 65001");
		//std::cerr << std::boolalpha << "this->CheckDate() == " << this->CheckDate() << std::endl;
		return { INT_CHECK, INT_CHECK, INT_CHECK };
	}
}