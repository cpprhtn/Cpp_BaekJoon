#include<iostream>
#include<string>
using namespace std;


int main()
{
	string str;
	cin >> str;
	int dp[5000];
	dp[0] = bool(str[0] - '0');
	dp[1] = dp[0];
	if (str[1] != '0' && (str[0] == '1' || (str[0] == '2' && str[1] <= '6')))
		dp[1] = 2;

	for (int i = 2; i < str.size(); i++)
	{
		dp[i] = dp[i - 1];
		if (str[i] == '0')
		{
			dp[i] = dp[i - 2];
			continue;
		}

		else if (str[i - 1] == '1' || (str[i - 1] == '2' && str[i] <= '6'))
			dp[i] += dp[i - 2];

		dp[i] %= 1000000;
	}

	printf("%d\n", dp[str.size() - 1]);

	return 0;
}
