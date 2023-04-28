#include "inout.h"

void read(std::vector<int> &vec)
{
	std::cout << "Enter number of values: ";
	int n;
	std::cin >> n;
	vec.resize(n);

	std::cout << "Enter values:  ";
	for (int i = 0; i < n; ++i)
		std::cin >> vec[i];
}