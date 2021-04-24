#include "../src/dies.hpp"


using namespace std;

int main()
{
	system("chcp 65001");

	dies a = { 2021, 1, 24 }; date b = { 2021, 12, 12 };

	std::cout << drand(a, b) << std::endl;
	std::cout << float_rand_result(1, 5) << std::endl;
	std::cout << float_rand_result(1, 5) << std::endl;
	std::cout << float_rand_result(1, 5) << std::endl;
	std::cout << float_rand_result(1, 5) << std::endl;
	std::cout << float_rand_result(1, 5) << std::endl;
	std::cout << float_rand_result(1, 5) << std::endl;
	std::cout << float_rand_result(1, 5) << std::endl;
	
	system("pause");
	return 0;
}