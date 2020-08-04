#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, s, m;
	vector<int> dp[1001];
	scanf("%d %d %d", &n, &s, &m);
	dp[0].push_back(s);
	for (int i = 0; i < n; i++)
	{
		int v;
		bool check[1001] = {};
		scanf("%d", &v);
		for (auto &cur : dp[i])
		{
			if (cur + v <= m && !check[cur + v])
				dp[i + 1].push_back(cur + v), check[cur + v] = 1;

			if (cur - v >= 0 && !check[cur - v])
				dp[i + 1].push_back(cur - v), check[cur - v] = 1;
		}
	}

	sort(dp[n].begin(), dp[n].end());
	printf("%d", (dp[n].empty() ? -1 : dp[n].back()));
}