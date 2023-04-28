#include "inout.h"

void print(const std::vector<int> &vec)
{
	std::cout << "Sorted values: ";
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}