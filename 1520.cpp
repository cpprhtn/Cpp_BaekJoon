#include <iostream>
using namespace std;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int map[502][502];
int dp[502][502];
bool v[501][501];
int n, m;
int solve(int x, int y)
{
	if (x == 0 || y == 0 || x == n + 1 || y == m + 1) return 0;
	if (v[x][y]) return dp[x][y];
	for (int i = 4; i--;)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (map[x][y] < map[nx][ny])
			dp[x][y] += solve(nx, ny);
	}
	v[x][y] = 1;
	return dp[x][y];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}
	v[1][1] = 1, dp[1][1] = 1;
	cout << solve(n, m);
}