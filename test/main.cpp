#include <iostream>

#include "../src/dies.hpp"


using namespace std;

int main()
{
	system("chcp 65001");

	dies a = { 1,1,1 }; dies b = { 2021, 10, 10 };
	std::cout << a.CHECK() << std::endl;
	a.input(2020, 1, 1);

	std::cout << a.CHECK() << std::endl;
	std::cout << b.CHECK() << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << a << std::endl;
	b.input(2020, 1, 11);
	dies d;
	d = a + 22;

	std::cout << b << std::endl;
	std::cout << ( b - a )  << std::endl;
	std::cout << ( d - a )  << std::endl;
	std::cout << a  << std::endl;
	std::cout << ++a  << std::endl;
	std::cout << a++ << std::endl;
	a += 10;
	std::cout << a << std::endl;
	a -= 10;
	std::cout << a << std::endl;
	std::cout << d.getDay() << std::endl;

	//sap[ fksodaifjsadio fjsoifajsfiosadjif b-a a-b чё за хута
	system("pause");
	return 0;
}