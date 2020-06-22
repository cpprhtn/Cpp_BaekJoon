#include <cstdio>

int dp[8][8];
int solve(int n, int k)
{
	if (k == 0)
		k = n;

	dp[1][1] = dp[1][0] = 1;

	if (dp[n][k])
		return dp[n][k];

	for (int i = 2; i <= n; i++)
	{
		dp[i - 1][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);

	}

	return dp[n][k];
}

int main()
{
	int n, m, k, S, M=1;
	long double ans = 0;
	scanf("%d %d %d", &n, &m, &k);

	do
	{
		ans += (long double)(solve(m, k)*solve(n - m, m - k)) / (long double)solve(n, m);
	} while (++k<=m);

	printf("%.11Lf", ans);
}