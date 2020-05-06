#include <iostream>
#include <vector>

using namespace std;

int main()
{
	static const int NO_COMPUTER = 10;
	int no_case;
	cin >> no_case;

	while(no_case--)
	{
		int num, ex, temp, result;
		vector<int> shit;
		cin >> num >> ex;
		num %= NO_COMPUTER;
		temp = num;

		for (int i = 0; i < ex; i++)
		{
			shit.push_back(temp);
			temp = (temp*num) % NO_COMPUTER;
			if (shit.front() == temp)
				break;

		}

		result = (ex-1) % shit.size();
		cout << (shit[result]==0?10:shit[result]) << endl;
	}

	return 0;
}
