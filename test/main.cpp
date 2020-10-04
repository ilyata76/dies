#include "../src/dies.hpp"


using namespace std;

int main()
{
	system("chcp 65001");

	dies a = { 2021, 1, 24 }; dies b = { 2021, 12, 12 };

	std::cout << drand(a, b) << std::endl;
	
	system("pause");
	return 0;
}