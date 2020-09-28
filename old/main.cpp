#include <iostream>
#include "DIES.h"



using namespace std;

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	dies a, b;
	cin >> a >> b;
	CALEN(a, b);
	system("pause");
	return 0;
}