#include <cstdio>
#include <algorithm>
typedef long long ll;
ll x, y, z;
int main()
{
	while (~scanf("%lld %lld", &x, &y))
	{
		z = y * 100 / x;
		if (z >= 99)
		{
			puts("-1\n");
			continue;
		}

		ll l = 1, r = x;
		ll ans = x;
		while (l <= r)
		{
			ll mid = (l + r) >> 1;
			if ((y + mid) * 100 / (x + mid) > z)
			{
				r = mid - 1;
				ans = std::min(ans, mid);
			}

			else l = mid + 1;
		}

		printf("%lld\n", ans);
	}
}