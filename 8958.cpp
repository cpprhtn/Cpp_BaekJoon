#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int n, sum, score;
	cin >> n;
	while (n--)
	{
		sum = 0, score = 0;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str.at(i) == 'O')
				sum += ++score;

			else
				score = 0;
		}

		cout << sum << endl;
	}
	
	return 0;
}