#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool dp[2500][2500];
int res[2501];
int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		dp[i][i] = 1;
		if (i != str.size() - 1 && str[i] == str[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int i = 2; i < str.size(); i++)
	{
		for (int j = 0; j + i < str.size(); j++)
		{
			if (str[j] == str[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = 1;
		}
	}

	res[0] = 1;
	for (int i = 1; i < str.size(); i++)
	{
		res[i] = i + 1;
		for (int j = 0; j <= i; j++)
		{
			if (dp[j][i])
			{
				res[i] = min(res[i], res[j - 1] + 1);
			}
		}
	}
	cout << res[str.size() - 1];
}