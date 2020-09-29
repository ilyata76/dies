#include <iostream>

#include "../src/dies.hpp"


using namespace std;

int main()
{
	system("chcp 65001");

	dies a = { 1,1,1 }; dies b = { 2021, 10, 10 };
	std::cout << a.CHECK() << std::endl;
	a.input(2020, 9, 32);

	std::cout << a.CHECK() << std::endl;
	std::cout << b.CHECK() << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a >= b) << std::endl;


	system("pause");
	return 0;
}