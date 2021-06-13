#include <iostream>
#include <vector>

int main()
{
	std::vector<bool> vec;
	int N, L, D;
	int ring = 0;

	std::cin >> N >> L >> D;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < L; j++)
		{
			vec.push_back(true);
		}

		for (int j = 0; j < 5; j++)
		{
			vec.push_back(false);
		}
	}

	for (;;)
	{
		if (ring > vec.size())
			break;
		if (vec[ring] == false)
			break;
		else
			ring += D;
	}

	std::cout << ring;
}