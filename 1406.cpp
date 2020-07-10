#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str;
	list<char> strl;
	int n;
	char cmd;
	cin >> str >> n;
	for (char i : str)
		strl.push_back(i);

	auto cosor = strl.end();
	while (n--)
	{
		cin >> cmd;
		switch (cmd)
		{
		case 'L':
			if (cosor!=strl.begin())
				cosor--;
			break;

		case 'D':
			if (cosor!=strl.end())
				cosor++;
			break;

		case 'B':
			if (cosor!=strl.begin())
				cosor = strl.erase(--cosor);
			break;

		case 'P':
			char temp;
			cin >> temp;
			cosor = strl.insert(cosor, temp);
			cosor++;
		}
	}

	for (char i : strl)
		cout << i;

	return 0;
}
