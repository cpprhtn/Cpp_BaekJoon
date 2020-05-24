#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> MV;

MV ju[300000];
multiset<int> bag;
int main()
{
	int n, k, m, v, c;
	long long ans = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &m, &v);
		ju[i] = { v, m };
	}

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &c);
		bag.insert(c);
	}

	sort(ju, ju + n);
	for (int i = n - 1; i >= 0; i--)
	{
		auto it = bag.lower_bound(ju[i].second);
		if (it != bag.end())
		{
			ans += ju[i].first;
			bag.erase(it);
		}

	}

	printf("%lld", ans);
}