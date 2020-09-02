#include <cstdio>
#include <algorithm>
using namespace std;

int a[10001], b[10001], sa[10001], sb[10001];
int main()
{
	int n, m;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			return 0;

		int ans = 0, pa = 0, pb = 0, it = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sa[i] = a[i] + sa[i - 1];
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &b[i]);
			sb[i] = b[i] + sb[i - 1];
			while (a[it] < b[i] && it < n) it++;
			if (it > n || a[it] != b[i]) continue;

			ans += max(sa[it] - sa[pa], sb[i] - sb[pb]);
			pa = it, pb = i;
		}
		ans += max(sa[n] - sa[pa], sb[m] - sb[pb]);
		printf("%d\n", ans);
	}
}