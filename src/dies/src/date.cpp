
#include "../date.hpp"



bool leapyear(int Y) {
	if (Y % 100 == 0) {
		if (Y % 400 == 0) return true;
		else return false;
	} else {
		if (Y % 4 == 0) return true;
		else return false;
	} return false;
}

bool check(int Y, int M, int D) {
	if (Y <= 0 || D <= 0 || M <= 0 || M > 12 || D > 31 || Y >= INT_CHECK) return false;
		if (M == 1) {
			if (D > 31) return false;
		} else if (M == 2 && leapyear(Y)) {
			if (D > 29) return false;
		} else if (M == 2 && !leapyear(Y)) {
			if (D > 28) return false;
		} else if (M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
			if (D > 31) return false;
		} else if (M == 4 || M == 6 || M == 9 || M == 11) {
			if (D > 30) return false;
		} else return false;
		return true;
}

bool dies::CHECK() {
	if (this->DD == INT_CHECK || 
		this->MM == INT_CHECK || 
		this->YYYY == INT_CHECK) 
			return false;
	else
		return true;
}

dies& dies::input(int Y, int M, int D) {
	if (check(Y, M, D)) {
		DD = D; MM = M; YYYY = Y;
		return *this;
	} else {
		DD = INT_CHECK; MM = INT_CHECK; YYYY = INT_CHECK;
		return *this;
	}
}

bool operator > (dies& a, dies& b) {
	if (a.CHECK() && b.CHECK()) {
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
		system("chcp 65001");
		std::cerr << std::boolalpha << "a.CHECK() == " << a.CHECK() << "; b.CHECK() == " << b.CHECK() << std::endl;
		return false;
	}
}

bool operator >= (dies& a, dies& b) {
	if (a.CHECK() && b.CHECK()) {
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
		system("chcp 65001");
		std::cerr << std::boolalpha << "a.CHECK() == " << a.CHECK() << "; b.CHECK() == " << b.CHECK() << std::endl;
		return false;
	}
}

bool operator < (dies& a, dies& b) {
	if (a.CHECK() && b.CHECK()) {
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
		system("chcp 65001");
		std::cerr << std::boolalpha << "a.CHECK() == " << a.CHECK() << "; b.CHECK() == " << b.CHECK() << std::endl;
		return false;
	}
}

bool operator <= (dies& a, dies& b) {
	if (a.CHECK() && b.CHECK()) {
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
		system("chcp 65001");
		std::cerr << std::boolalpha << "a.CHECK() == " << a.CHECK() << "; b.CHECK() == " << b.CHECK() << std::endl;
		return false;
	}
}

bool operator == (dies& a, dies& b) {
	if (a.CHECK() && b.CHECK()) {
		if (a.YYYY = b.YYYY) {
			if (a.MM == b.MM) {
				if (a.DD == b.DD) return true;
				else return false;
			} else return false;
		} else return false;
	} else {
		system("chcp 65001");
		std::cerr << std::boolalpha << "a.CHECK() == " << a.CHECK() << "; b.CHECK() == " << b.CHECK() << std::endl;
		return false;
	}
}

std::ostream& operator << (std::ostream& out, dies& X) {
	if (X.CHECK()) {
		out
			<< std::setw(4) << std::setfill('0') << X.getYear() << "."
			<< std::setw(2) << std::setfill('0') << X.getMonth() << "."
			<< std::setw(2) << std::setfill('0') << X.getDay();
		return out;
	} else { 
		system("chcp 65001");
		out 
			<< std::boolalpha << "X.CHECK() == " << X.CHECK() << std::endl;
		return out;
	}
}

std::istream& operator >> (std::istream& in, dies& X) {
	char A = ' '; in >> X.YYYY >> A >> X.MM >> A >> X.DD;
	if (A == '.') {
		if (check(X.YYYY, X.MM, X.DD)) {
			return in;
		} else {
			X.YYYY = INT_CHECK; X.MM = INT_CHECK; X.DD = INT_CHECK; return in;
		}
	} else {
		X.YYYY = INT_CHECK; X.MM = INT_CHECK; X.DD = INT_CHECK; return in;
	}


	return in;
}