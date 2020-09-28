

#include "DIES.h"
#pragma warning (disable : 26444)

using namespace std;

int MOUNTHDETERMINE(int& CL, int& k, bool& visok, int& DAYS, int& DAYSO);
int MONTHDETERMINE(int& k, int& DAYS, int& DAYSO);
int FORMONTHDETERMINE(int& CL, int& k, int& DAYS, int& DAYSO);

int startmonthVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth);
int monthVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth);
void forMVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth);


dies& dies::input(int D, int M, int Y)
{
	if (check(D, M, Y)) { DD = D; MM = M; YYYY = Y; return *this; }
	else { cout << "\n \t#DIES.h# Date initialization error \"dies(D, M, Y)\" Date: -> 1.1.1 \n"; this->~dies(); return input(1, 1, 1); }
}
bool operator<(dies& a, dies& b)
{
	if (a.YYYY < b.YYYY) return true;
	if (a.YYYY > b.YYYY) return false;
	if (a.YYYY == b.YYYY)
	{
		if (a.MM < b.MM) return true;
		if (a.MM > b.MM) return false;
		if (a.MM == b.MM)
		{
			if (a.DD < b.DD) return true;
			if (a.DD > b.DD) return false;
			if (a.DD == b.DD) return false;
		}
	}
	return false;
}
bool operator>(dies& a, dies& b)
{
	if (a.YYYY > b.YYYY) return true;
	if (a.YYYY < b.YYYY) return false;
	if (a.YYYY == b.YYYY)
	{
		if (a.MM > b.MM) return true;
		if (a.MM < b.MM) return false;
		if (a.MM == b.MM)
		{
			if (a.DD > b.DD) return true;
			if (a.DD < b.DD) return false;
			if (a.DD == b.DD) return false;
		}
	}
	return false;
}
bool operator>=(dies& a, dies& b)
{
	if (a.YYYY > b.YYYY) return true;
	if (a.YYYY < b.YYYY) return false;
	if (a.YYYY == b.YYYY)
	{
		if (a.MM > b.MM) return true;
		if (a.MM < b.MM) return false;
		if (a.MM == b.MM)
		{
			if (a.DD > b.DD) return true;
			if (a.DD < b.DD) return false;
			if (a.DD == b.DD) return true;
		}
	}
	return false;
}
bool operator<=(dies& a, dies& b)
{
	if (a.YYYY < b.YYYY) return true;
	if (a.YYYY > b.YYYY) return false;
	if (a.YYYY == b.YYYY)
	{
		if (a.MM < b.MM) return true;
		if (a.MM > b.MM) return false;
		if (a.MM == b.MM)
		{
			if (a.DD < b.DD) return true;
			if (a.DD > b.DD) return false;
			if (a.DD == b.DD) return true;
		}
	}
	return false;
}
bool operator==(dies& a, dies& b)
{
	if (a.YYYY == b.YYYY)
	{
		if (a.MM == b.MM)
		{
			if (a.DD == b.DD)
				return true;
			else return false;
		}
		else return false;
	}
	else return false;

}
istream& operator>>(istream& in, dies& a)
{
	char A; in >> a.DD >> A >> a.MM >> A >> a.YYYY;
	if (A == '.')
	{
		if (a.check(a.DD, a.MM, a.YYYY)) return in;
		else { cout << "\n \t#DIES.h# Date initialization error \">>(...)\" Date -> 1.1.1 \n"; a.DD = a.MM = a.YYYY = 1; return in; }
	}
	else { cout << "\n\t#DIES.h# Invalid date format \">>(...)\" Date: -> 1.1.1 \n"; a.DD = a.MM = a.YYYY = 1; return in; }
}
ostream& operator<<(ostream& out, const dies& a)
{
	out << setw(2) << setfill('0') << a.DD << "."
		<< setw(2) << setfill('0') << a.MM << "."
		<< setw(4) << setfill('0') << a.YYYY;
	return out;
}
dies dies::operator=(dies a)
{
	DD = a.DD; MM = a.MM; YYYY = a.YYYY; return *this;
}
int operator-(dies a, dies b)
{
	if (b < a) { dies temp = { 1,1,1 }; temp = a; a = b; b = temp; }
	int Yr = b.YYYY - a.YYYY;
	int aM = 0, bM = 0, cM = 0; int itM = 0;
	if (Yr) {
		if (a.MM == 1 || a.MM == 3 || a.MM == 5 || a.MM == 7 || a.MM == 8 || a.MM == 10 || a.MM == 12) aM += (31 - a.DD) + 1;
		if (a.MM == 2 && a.leapyear(a.YYYY)) aM += (29 - a.DD) + 1;
		if (a.MM == 2 && !a.leapyear(a.YYYY)) aM += (28 - a.DD) + 1;
		if (a.MM == 4 || a.MM == 6 || a.MM == 9 || a.MM == 11) aM += (30 - a.DD) + 1;

		for (itM = a.MM + 1; itM != 13; itM++)
		{
			if (itM == 1 || itM == 3 || itM == 5 || itM == 7 || itM == 8 || itM == 10 || itM == 12) aM += 31;
			if (itM == 2 && a.leapyear(a.YYYY)) aM += 29;
			if (itM == 2 && !a.leapyear(a.YYYY)) aM += 28;
			if (itM == 4 || itM == 6 || itM == 9 || itM == 11) aM += 30;
		}

		for (int i = 1, Yr = b.YYYY - a.YYYY + 1 - 2; Yr > 0; Yr--, i++)
		{
			for (itM = 1; itM != 13; itM++)
			{
				if (itM == 1 || itM == 3 || itM == 5 || itM == 7 || itM == 8 || itM == 10 || itM == 12) cM += 31;
				if (itM == 2 && a.leapyear(a.YYYY + i)) cM += 29;
				if (itM == 2 && !a.leapyear(a.YYYY + i)) cM += 28;
				if (itM == 4 || itM == 6 || itM == 9 || itM == 11) cM += 30;

			}
		}
		if (b.MM != 1)
		{
			for (itM = 1; itM != b.MM; itM++)
			{
				if (itM == 1 || itM == 3 || itM == 5 || itM == 7 || itM == 8 || itM == 10 || itM == 12) bM += 31;
				if (itM == 2 && b.leapyear(b.YYYY)) bM += 29;
				if (itM == 2 && !b.leapyear(b.YYYY)) bM += 28;
				if (itM == 4 || itM == 6 || itM == 9 || itM == 11) bM += 30;
			}
		}
		bM += b.DD;
	}
	else if (a.YYYY == b.YYYY && a.MM == b.MM && a.DD == b.DD) { return (0 + 1); }
	else if (a.YYYY == b.YYYY && a.MM == b.MM && a.DD != b.DD) { return (abs(b.DD - a.DD) - 1 + 1); }
	else if ((a.YYYY == b.YYYY && a.MM != b.MM && a.DD != b.DD) || (a.YYYY == b.YYYY && a.MM != b.MM && a.DD == b.DD))
	{
		if (b.MM != 1)
		{
			if (a.MM == 1 || a.MM == 3 || a.MM == 5 || a.MM == 7 || a.MM == 8 || a.MM == 10 || a.MM == 12) aM += (31 - a.DD) + 1;
			if (a.MM == 2 && a.leapyear(a.YYYY)) aM += (29 - a.DD) + 1;
			if (a.MM == 2 && !a.leapyear(a.YYYY)) aM += (28 - a.DD) + 1;
			if (a.MM == 4 || a.MM == 6 || a.MM == 9 || a.MM == 11) aM += (30 - a.DD) + 1;

			for (itM = a.MM + 1; itM != b.MM; itM++)
			{
				if (itM == 1 || itM == 3 || itM == 5 || itM == 7 || itM == 8 || itM == 10 || itM == 12) bM += 31;
				if (itM == 2 && b.leapyear(b.YYYY)) bM += 29;
				if (itM == 2 && !b.leapyear(b.YYYY)) bM += 28;
				if (itM == 4 || itM == 6 || itM == 9 || itM == 11) bM += 30;
			}
		}
		bM += b.DD;
		return (bM + aM - 1 + 1);
	}

	return (aM + bM + cM - 1 + 1);
}
dies dies::operator+(int X)
{
	int XD = 0;
	while (true)
	{
		if (MM == 1 || MM == 3 || MM == 5 || MM == 7 || MM == 8 || MM == 10 || MM == 12)
		{
			if (DD + X <= 31) { DD = DD + X; if (MM == 13) { MM = 1; YYYY++; } break; }
			else if (DD + X == 32) { DD = 1, MM++; if (MM == 13) { MM = 1; YYYY++; } break; }
			else { XD = 31 - DD; DD = 1; MM++; X = X - XD - 1; }
		}
		else if (MM == 2 && leapyear(YYYY))
		{
			if (DD + X <= 29) { DD = DD + X; if (MM == 13) { MM = 1; YYYY++; } break; }
			else if (DD + X == 30) { DD = 1, MM++; if (MM == 13) { MM = 1; YYYY++; } break; }
			else { XD = 29 - DD; DD = 1; MM++; X = X - XD - 1; }
		}
		else if (MM == 2 && !leapyear(YYYY))
		{
			if (DD + X <= 28) { DD = DD + X; if (MM == 13) { MM = 1; YYYY++; } break; }
			else if (DD + X == 29) { DD = 1, MM++; if (MM == 13) { MM = 1; YYYY++; } break; }
			else { XD = 28 - DD; DD = 1; MM++; X = X - XD - 1; }
		}
		else if (MM == 4 || MM == 6 || MM == 9 || MM == 11)
		{
			if (DD + X <= 30) { DD = DD + X; if (MM == 13) { MM = 1; YYYY++; } break; }
			else if (DD + X == 31) { DD = 1, MM++; if (MM == 13) { MM = 1; YYYY++; } break; }
			else { XD = 30 - DD; DD = 1; MM++; X = X - XD - 1; }
		}
		if (MM == 13) { MM = 1; YYYY++; }
	}
	return *this;
}
dies dies::operator-(int X)
{
	while (X)
	{
		DD = DD - 1; X--;
		if (DD == 0)
		{
			if (MM == 8 || MM == 2) { MM--; DD = 31; }
			else if (MM == 1) { MM = 12; YYYY--; DD = 31; }
			else if (MM == 5 || MM == 7 || MM == 10 || MM == 12) { MM = MM - 1;  DD = 30; }
			else if (MM == 3 && leapyear(YYYY)) { MM--; DD = 29; }
			else if (MM == 3 && !leapyear(YYYY)) { MM--; DD = 28; }
			else if (MM == 4 || MM == 6 || MM == 9 || MM == 11) { MM--; DD = 31; }
		}
		if (YYYY <= 0) { cout << "\n\t #DIES.h# Year is zero or less then zero \"YYYY == 0\" Date: -> 1.1.1 \n"; return input(1, 1, 1); }
	}
	return *this;
}
bool dies::leapyear(int Y)
{
	bool leap = false;
	if (Y % 100 == 0) { if (Y % 400 == 0) leap = true; else leap = false; }
	else { if (Y % 4 == 0) leap = true; else leap = false; }
	return leap;
}
bool dies::check(int D, int M, int Y)
{
	bool leap = leapyear(Y);
	for (itMONTH = month.begin(); itMONTH != month.end(); itMONTH++)
	{
		if (M == itMONTH->first) break;
	}
	if (Y <= 0) return false;
	if (M > 12 || M <= 0) { ENDL; cout << " \t#DIES.h# Month entered incorrectly"; return false; }
	if (M) {
		if (M == 1) if (D <= 0 || D > 31) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 31 days"; return false; }
		if (M == 2 &&
			leap == true) if (D <= 0 || D > 29) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 29 days in this leap year: " << Y; return false; }
		if (M == 2 &&
			leap == false) if (D <= 0 || D > 28) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 28 days in this non-leap year: " << Y; return false; }
		if (M == 3) if (D <= 0 || D > 31) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 31 days "; return false; }
		if (M == 4) if (D <= 0 || D > 30) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 30 days "; return false; }
		if (M == 5) if (D <= 0 || D > 31) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 31 days "; return false; }
		if (M == 6) if (D <= 0 || D > 30) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 30 days "; return false; }
		if (M == 7) if (D <= 0 || D > 31) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 31 days "; return false; }
		if (M == 8) if (D <= 0 || D > 31) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 31 days "; return false; }
		if (M == 9) if (D <= 0 || D > 30) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 30 days "; return false; }
		if (M == 10) if (D <= 0 || D > 31) { cout << "\n \t#DIES.h#  In the month \"" << itMONTH->second << "\" - 31 days "; return false; }
		if (M == 11) if (D <= 0 || D > 30) { cout << "\n In the month \"" << itMONTH->second << "\" - 30 days "; return false; }
		if (M == 12) if (D <= 0 || D > 31) { cout << "\n In the month \"" << itMONTH->second << "\" - 31 days "; return false; }
	}
	return true;
}
dies drand(dies a, dies b)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	float ADD = float(a.DD), BDD = float(b.DD);
	float AMM = float(a.MM), BMM = float(b.MM);
	float AYYYY = float(a.YYYY), BYYYY = float(b.YYYY);
	if (b < a) { dies temp{ 1,1,1 }; temp = a; a = b; b = temp; }
	dies c;
	float CDD = float(c.DD), CMM = float(c.MM), CYYYY = float(c.YYYY);
	float Y = 0;
	if (AYYYY != BYYYY)
	{
		Y = 0; uniform_real_distribution<float> dist(AYYYY, BYYYY + 1);
		Y = dist(mt); CYYYY = Y; c.YYYY = int(CYYYY);
		CYYYY = float(int(CYYYY));
		if (CYYYY == AYYYY)
		{
			Y = 0; uniform_real_distribution<float> distMM(AMM, 12.0 + 1);
			Y = distMM(mt); CMM = Y; c.MM = int(CMM);
			CMM = float(int(CMM));
			if (CMM == AMM)
			{
				Y = 0; uniform_real_distribution<float> distDD(ADD, BDD + 1);
				Y = distDD(mt); CDD = Y; c.DD = int(CDD);
			}
			else {
				Y = 0;
				if (CMM == 1 || CMM == 3 || CMM == 5 || CMM == 7 || CMM == 8 || CMM == 10 || CMM == 12) { uniform_real_distribution<float> distDD(1.0, 31.0 + 1.0); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, 29.0 + 1.0); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && !c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, 28.0 + 1.0); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 4 || CMM == 6 || CMM == 9 || AMM == 11) { uniform_real_distribution<float> distDD(1.0, 30.0 + 1.0); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else { c.DD = 1; }
			}
		}
		else if (CYYYY != AYYYY && CYYYY == BYYYY)
		{
			Y = 0; uniform_real_distribution<float> distMM(1, BMM + 1);
			Y = distMM(mt);	CMM = Y; c.MM = int(CMM);
			CMM = float(int(CMM));
			if (CMM == BMM)
			{
				Y = 0; uniform_real_distribution<float> distDD(ADD, BDD + 1);
				Y = distDD(mt); CDD = Y; c.DD = int(CDD);
			}
			else {
				Y = 0; uniform_real_distribution<float> distDD(1.0, 28.0 + 1.0);
				if (CMM == 1 || CMM == 3 || CMM == 5 || CMM == 7 || CMM == 8 || CMM == 10 || CMM == 12) { uniform_real_distribution<float> distDD(1.0, 31.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, 29.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && !c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, 28.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 4 || CMM == 6 || CMM == 9 || AMM == 11) { uniform_real_distribution<float> distDD(1.0, 30.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else { c.DD = 1; }
			}
		}
		else if (CYYYY != AYYYY && CYYYY != BYYYY)
		{
			Y = 0;	uniform_real_distribution<float> distMM(1, 12.0 + 1);
			Y = distMM(mt);	CMM = Y; c.MM = int(CMM); CMM = float(int(CMM));
			Y = 0;
			if (CMM == 1 || CMM == 3 || CMM == 5 || CMM == 7 || CMM == 8 || CMM == 10 || CMM == 12) { uniform_real_distribution<float> distDD(1.0, 31.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
			else if (CMM == 2 && c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, 29.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
			else if (CMM == 2 && !c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, 28.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
			else if (CMM == 4 || CMM == 6 || CMM == 9 || AMM == 11) { uniform_real_distribution<float> distDD(1.0, 30.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
			else { c.DD = 1; }
		}
	}
	if (AYYYY == BYYYY)
	{
		if (a == b) return a;
		CYYYY = AYYYY; c.YYYY = int(CYYYY);
		CYYYY = float(int(CYYYY));
		if (AMM != BMM)
		{
			Y = 0;	uniform_real_distribution<float> distMM(AMM, BMM + 1);
			Y = distMM(mt);	CMM = Y; c.MM = int(CMM); CMM = float(int(CMM));
			CMM = float(int(CMM));
			if (CMM - AMM != 0 && BMM - CMM != 0)
			{
				Y = 0;
				if (CMM == 1 || CMM == 3 || CMM == 5 || CMM == 7 || CMM == 8 || CMM == 10 || CMM == 12) { uniform_real_distribution<float> distDD(1.0, 31.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, 29.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && !c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, 28.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 4 || CMM == 6 || CMM == 9 || AMM == 11) { uniform_real_distribution<float> distDD(1.0, 30.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else { c.DD = 1; }
			}
			else if (CMM - AMM == 0)
			{
				Y = 0;
				if (CMM == 1 || CMM == 3 || CMM == 5 || CMM == 7 || CMM == 8 || CMM == 10 || CMM == 12) { uniform_real_distribution<float> distDD(ADD, 31.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(ADD, 29.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && !c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(ADD, 28.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 4 || CMM == 6 || CMM == 9 || AMM == 11) { uniform_real_distribution<float> distDD(ADD, 30.0 + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else { c.DD = 1; }
			}
			else if (BMM - CMM == 0)
			{
				Y = 0;
				if (CMM == 1 || CMM == 3 || CMM == 5 || CMM == 7 || CMM == 8 || CMM == 10 || CMM == 12) { uniform_real_distribution<float> distDD(1.0, BDD + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, BDD + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 2 && !c.leapyear(int(CYYYY))) { uniform_real_distribution<float> distDD(1.0, BDD + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else if (CMM == 4 || CMM == 6 || CMM == 9 || AMM == 11) { uniform_real_distribution<float> distDD(1.0, BDD + 1); Y = distDD(mt); CDD = Y; c.DD = int(CDD); }
				else { c.DD = 1; }
			}
		}
		else
		{
			CMM = AMM; c.MM = int(CMM);
			Y = 0; uniform_real_distribution<float> distDD(ADD, BDD + 1);
			Y = distDD(mt); CDD = Y; c.DD = int(CDD);
		}
	}
	return c;
}




/////////////////////////////////////////////////////////////////////////
//							   КАЛЕНДАРЬ
/////////////////////////////////////////////////////////////////////////
bool viso(int& year)
{
	bool viso;
	if (year % 100 == 0)
	{
		if (year % 400 == 0) viso = true;
		else viso = false;
	}
	else
	{
		if (year % 4 == 0) viso = true;
		else viso = false;
	}
	return viso;
}
void swap(int& a, int& b)
{
	int temp; temp = a; a = b; b = temp;
}
char s[] = "  "; int YESTART = 1; int kYESTART = 0;
map <int, string> weekday = {
	{0, "ПН"},
	{1, "ВТ"},
	{2, "СР"},
	{3, "ЧТ"},
	{4, "ПТ"},
	{5, "СБ"},
	{6, "ВС"}
}; map <int, string> ::iterator itWEEKDAY = weekday.begin();
map <int, string> mounth = {
	{1, "Январь"},
	{2, "Февраль"},
	{3, "Март"},
	{4, "Апрель"},
	{5, "Май"},
	{6, "Июнь"},
	{7, "Июль"},
	{8, "Август"},
	{9, "Сентябрь"},
	{10, "Октябрь"},
	{11, "Ноябрь"},
	{12, "Декабрь"},
}; map <int, string> ::iterator itMOUNTH = mounth.begin();
int MOUNTHDETERMINE(int& CL, int& k, bool& visok, int& DAYS, int& DAYSO)
{
	if (CL > 5000) cout << "\n считаем...\n";
	k = kYESTART;
	int day = 0; int n = 0; DAYS = 31;
	for (itWEEKDAY = weekday.begin(); itWEEKDAY != weekday.end(); itWEEKDAY++)
	{
		if (itWEEKDAY == weekday.begin()) { n -= k; k = 0; }
		for (day = n + 1; day <= DAYS;) {
			if (day <= 0) { day += 7; k++; }
			else { day += 7; }
		}
		n++;
	}
	DAYSO = DAYS; int YE = YESTART;
	visok = viso(YE);
	if (visok) DAYS = 29; else DAYS = 28;
	FORMONTHDETERMINE(CL, k, DAYS, DAYSO);
	swap(DAYS, DAYSO);														// они свапаются в функциях FOR, надо возвращать
	return k;
}
int MONTHDETERMINE(int& k, int& DAYS, int& DAYSO) {
	int day = 0;  int n = 0;
	for (itWEEKDAY = weekday.begin(); itWEEKDAY != weekday.end(); itWEEKDAY++)
	{
		if (itWEEKDAY == weekday.begin() && DAYSO == 31) {
			n = -k - 3; k = 0;
		}
		if (itWEEKDAY == weekday.begin() && DAYSO == 30) {
			n = -k - 2; k = 0;
		}
		if (itWEEKDAY == weekday.begin() && DAYSO == 29) {
			n = -k - 1; k = 0;
		}
		if (itWEEKDAY == weekday.begin() && DAYSO == 28) {
			n = -k - 0; k = 0;
		}
		if (n <= -7) n = n + 7;
		for (day = n + 1; day <= DAYS;) {
			if (day <= 0) { day += 7; k++; }
			else if (day > 0 && day <= DAYS) { day += 7; }
		}
		n++;
	}
	return k;
}
int FORMONTHDETERMINE(int& CL, int& k, int& DAYS, int& DAYSO)
{
	bool visok;
	for (int i = 2; i <= CL; i++)
	{
		if (CL > 5000 && i == CL / 2) cout << "...половину посчитали\n";
		if ((i - 2) % 12 == 0)
		{
			int YE = YESTART + (i - 1) / 12;
			visok = viso(YE);
			if (visok) DAYS = 29;
			else DAYS = 28;
			DAYSO = 31;
		}
		if ((i - 13) % 12 == 0)
		{
			DAYS = 31; DAYSO = 31;
		}
		if ((i - 8) % 12 == 0)
		{
			DAYS = 31; DAYSO = 31;
		}

		if (DAYS == 28)
		{
			k = MONTHDETERMINE(k, DAYS, DAYSO);
			DAYSO = 28; DAYS = 31;
		}
		else if (DAYS == 29)
		{
			k = MONTHDETERMINE(k, DAYS, DAYSO);
			DAYSO = 29; DAYS = 31;
		}
		else if (DAYS == 30)
		{
			k = MONTHDETERMINE(k, DAYS, DAYSO);
			DAYSO = 30; DAYS = 31;
		}
		else if (DAYS == 31)
		{
			k = MONTHDETERMINE(k, DAYS, DAYSO);
			DAYSO = 31; DAYS = 30;
		}
	}
	return k;
}
int startmonthVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth)
{
	cout << "===============================================\n\n";
	int day = 0; int n = 0; int moFor = mo; int YE = year;
	if (moFor >= ((moFor) / 12) * 13)
	{
		YE = year + ((moFor - 1) / 12);
		moFor -= 12 * ((moFor - 1) / 12);

	}
	for (itMOUNTH = mounth.begin(); itMOUNTH != mounth.end(); itMOUNTH++)
	{
		if (itMOUNTH->first == moFor) {
			if (CMonth == 1) // ne nado dop usloviy - perviy mecyac
			{
				cout << "=========================|" << YE << " " << endl;
			}
			cout << "     " << itMOUNTH->second;
			if (CMonth == 2) cout << "   " << YE;
			cout << endl;

		}
	}
	for (itWEEKDAY = weekday.begin(); itWEEKDAY != weekday.end(); itWEEKDAY++)
	{							// вывод первого(выбранного) месяца
		cout << itWEEKDAY->second << " ";
		if (itWEEKDAY == weekday.begin()) { n -= k; k = 0; }
		for (day = n + 1; day <= DAYS;) {
			if (day <= 0) {
				printf(" %s ", s);
				day += 7;
				k++;
			}
			else {
				printf(" %02d ", day);
				day += 7;
			}

		}
		n++;
		cout << endl;
	}
	DAYSO = DAYS;
	if (mo == 1)
	{
		if (viso(year)) DAYS = 29;
		else DAYS = 28;
	}
	if (mo == 2 || mo == 4 || mo == 6 || mo == 7 || mo == 9 || mo == 11 || mo == 12)
	{
		DAYS = 31;
	}
	else DAYS = 30;

	forMVERT(mo, COUNT, k, DAYS, DAYSO, year, CMonth);

	return k;
}
int monthVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth)
{
	int day = 0; int n = 0; int moFor = mo; int YE = year;
	if (moFor >= ((moFor) / 12) * 12)
	{
		YE = year + ((moFor - 1) / 12);
		moFor -= 12 * ((moFor - 1) / 12);
	}
	for (itMOUNTH = mounth.begin(); itMOUNTH != mounth.end(); itMOUNTH++)
	{
		if (itMOUNTH->first == moFor)
		{
			if (CMonth == 1 && moFor == 1)
			{
				cout << "=========================|" << YE << " " << endl;
			}
			cout << "     " << itMOUNTH->second;
			if (CMonth == 2) cout << "   " << YE;
			cout << endl;
		}
	}
	for (itWEEKDAY = weekday.begin(); itWEEKDAY != weekday.end(); itWEEKDAY++)
	{
		cout << itWEEKDAY->second << " ";
		if (itWEEKDAY == weekday.begin() && DAYSO == 31) {		// условия
			n = -k - 3; k = 0;									// для
		}														// сдвига
		if (itWEEKDAY == weekday.begin() && DAYSO == 30) {		// от предыдущего
			n = -k - 2; k = 0;									// месяца
		}
		if (itWEEKDAY == weekday.begin() && DAYSO == 29) {
			n = -k - 1; k = 0;
		}
		if (itWEEKDAY == weekday.begin() && DAYSO == 28) {
			n = -k - 0; k = 0;
		}
		if (n <= -7) n = n + 7;
		// если количество "отступов" в нынешнем месяце превышает
		// количество дней в неделе в силу форумлы - сдвигаемся на эту неделю
		// оправдано тем, что если оступов больше 4х, происходит сдвиг в предыдущем месяце
		// и выход 1-2 дней на новый столбец
		// по алгоритму: предпоследний столбец должен оставить за собой полосу пустых клеток
		for (day = n + 1; day <= DAYS;)
		{

			if (day <= 0)
			{
				printf(" %s ", s);
				day += 7;
				k++;
			}
			else if (day > 0 && day <= DAYS) {
				printf(" %02d ", day);
				day += 7;
			}

		}
		cout << endl; n++;
	}
	cout << "\n"; return k;
}
void forMVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth)
{												// функция вывода нескольких следующих друг за другом месяцев
	bool visok; int moF;
	cout << endl;
	for (int i = mo + 1; i < COUNT + mo; i++)	// mo+1 т.к. учтён предыдущий месяц
	{
		if ((i - 2) % 12 == 0)					// если февраль
		{
			int YE = year + (i - 1) / 12;
			visok = viso(YE);					// високосного года?
			if (visok) DAYS = 29;
			else DAYS = 28;
		}
		if ((i - 13) % 12 == 0)
		{										// "13" месяц - следующий январь
			DAYS = 31; DAYSO = 31;				// его прошлым был декабрь с 31 днём
		}
		if ((i - 8) % 12 == 0)
		{
			DAYS = 31; DAYSO = 31;				 // июль-август
		}
		if (DAYS == 28)
		{
			moF = i;
			k = monthVERT(moF, COUNT, k, DAYS, DAYSO, year, CMonth);
			DAYSO = 28; DAYS = 31;
		}
		else if (DAYS == 29)
		{
			moF = i;
			k = monthVERT(moF, COUNT, k, DAYS, DAYSO, year, CMonth);
			DAYSO = 29; DAYS = 31;
		}
		else if (DAYS == 30)
		{
			moF = i;
			k = monthVERT(moF, COUNT, k, DAYS, DAYSO, year, CMonth);
			DAYSO = 30; DAYS = 31;
		}
		else if (DAYS == 31)
		{
			moF = i;
			k = monthVERT(moF, COUNT, k, DAYS, DAYSO, year, CMonth);
			DAYSO = 31; DAYS = 30;
		}
	}
}
void CALEN(dies a, dies b)
{
	if (b < a) { dies temp{ 1,1,1 }; temp = a; a = b; b = temp; }
	int DAYS = 0, DAYSO = 0; int k = 0; bool visok; int CL, COUNT;
	CL = abs(YESTART - a.YYYY) * 12 + a.MM;
	k = MOUNTHDETERMINE(CL, k, visok, DAYS, DAYSO);

	if (b.YYYY > a.YYYY)							// -1, т.к. первый год заполняется отдельно
													// +1 отсутствует, т.к. второй год заполняется отдельно 
	{
		COUNT = (12 - a.MM + 1) + (b.MM) + abs(b.YYYY - a.YYYY - 1) * 12;
	}
	else if (b.YYYY == a.YYYY)
	{
		COUNT = b.MM - a.MM + 1;
	}
	int CMonth = 2;
	k = startmonthVERT(a.MM, COUNT, k, DAYS, DAYSO, a.YYYY, CMonth);

}


//