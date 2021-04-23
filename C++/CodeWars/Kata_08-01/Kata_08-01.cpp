#include <iostream>
#include <vector>

using namespace std;

int count_sheep(vector<bool> arr)
{
	unsigned int sum = 0;
	for (int i : arr)
	{
		if (i == true)
			sum++;
	}
	return sum;
}

void main()
{
	vector<bool> arr = { true,  true,  true,  false,
						true,  true,  true,  true ,
						true,  false, true,  false,
						true,  false, false, true ,
						true,  true,  true,  true ,
						false, false, true,  true };

	int sum = count_sheep(arr);
	cout << sum;
	system("pause>nul");
}
