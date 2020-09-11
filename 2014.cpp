#include <cstdio>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

ll LMT = (1 << 31) - 1;
set<ll> S;
vector<ll> prime;

int main()
{
	int k, n;
	ll num, ans = 0, cnt = 0;
	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++)
	{
		scanf("%lld", &num);
		prime.push_back(num);
		S.insert(num);
	}

	while (cnt<n)
	{
		num = *S.begin();
		S.erase(S.begin());

		if (ans < num) ans = num, cnt++;

		else if (ans == num) continue;

		for (ll &i : prime)
		{
			ll tmp = num * i;
			if (tmp > LMT) break;
			S.insert(tmp);
			if (S.size() > n)
				S.erase(--S.end());
		}
	}

	printf("%lld", ans);
}