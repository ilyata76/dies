#pragma once
#ifndef DIES_H 
#define DIES_H

	#include <iostream>
	#include <map>
	#include <iterator>
	#include <iomanip>
	#include <random>
	#include <windows.h>

	using namespace std;
	
class dies
{
public:
	int DD, MM, YYYY;

	dies() { DD = 1; MM = 1; YYYY = 1; };
	dies(int x) { DD = x; MM = x, YYYY = x; }
	dies(int D, int M, int Y) { DD = D, MM = M, YYYY = Y; };

	map <int, string> month = { {1, "January"}, {2, "February"}, {3, "March"}, {4, "April"}, {5, "May"}, {6, "June"}, {7, "July"},
			{8, "August"}, {9, "September"}, {10, "October"}, {11, "November"}, {12, "Cucumber"},
	}; map <int, string> ::iterator itMONTH = month.begin();

	dies& input(int D, int M, int Y);											// c.input(1,1,1)

	bool leapyear(int Y);
	bool check(int D, int M, int Y);											// �������� ����������� ����� ������

	friend bool operator > (dies& a, dies& b);
	friend bool operator < (dies& a, dies& b);
	friend bool operator <= (dies& a, dies& b);
	friend bool operator >= (dies& a, dies& b);
	friend bool operator == (dies& a, dies& b);
	friend istream& operator>>(istream& in, dies& a);
	friend ostream& operator<<(ostream& out, const dies& a);
	dies operator=(dies a);
	friend int operator -(dies a, dies b);										// ������� � ���� ������� ���
	friend dies drand(dies a, dies b);											// <random>-���� �� ��������� a-b

	dies operator+(int X);														// ������� ����, ���� �� � �������� ��������� X ����
	dies operator-(int X);														// ������� X ����

	~dies() {};

	friend int MOUNTHDETERMINE(int& CL, int& k, bool& visok, int& DAYS, int& DAYSO);
	friend int MONTHDETERMINE(int& k, int& DAYS, int& DAYSO);
	friend int FORMONTHDETERMINE(int& CL, int& k, int& DAYS, int& DAYSO);

	friend int startmonthVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth);
	friend int monthVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth);
	friend void forMVERT(int& mo, int& COUNT, int& k, int& DAYS, int& DAYSO, int& year, int& CMonth);
	friend void CALEN(dies a, dies b);

};
void CALEN(dies a, dies b);
	typedef dies date;
	#define _ "  "
	#define ENDL cout<<endl
#endif // DIES_H
			// >> : DD.MM.YYYY
			// dies a = 1; -->> 1.1.1
			// error -->> 1.1.1
