#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, ans1 = 1, ans2 = 1;
	string str;
	cin >> n >> str;

	for (int i = 1, pos=0; i < n; i++)
	{
		if (str[i] == str[pos])
		{
			pos = (pos + 1) % ans1;
		}

		else
		{
			pos = 0, ans1 = i + 1;
		}
	}

	reverse(str.begin(), str.end());

	for (int i = 1, pos = 0; i < n; i++)
	{
		if (str[i] == str[pos])
		{
			pos = (pos + 1) % ans2;
		}

		else
		{
			pos = 0, ans2 = i + 1;
		}
	}

	printf("%d", min(ans1, ans2));
}