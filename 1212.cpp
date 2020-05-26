#include<iostream>
#include<string>

using namespace std;

int main()
{
	string o, ans;
	cin >> o;

	for (int i = 0; i < o.size(); i++)
	{
		switch (o.at(i))
		{
		case '0':
			ans += "000"; break;
		case '1':
			ans += "001"; break;
		case '2':
			ans += "010"; break;
		case '3':
			ans += "011"; break;
		case '4':
			ans += "100"; break;
		case '5':
			ans += "101"; break;
		case '6':
			ans += "110"; break;
		case '7':
			ans += "111"; break;

		}

	}

	while (ans.size() != 1 && ans.front()=='0')
	{
		if (ans.front() == '0')
			ans.erase(ans.begin());
	}
	
	cout << ans << endl;
}
