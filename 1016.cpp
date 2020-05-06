#include <cstdio>

typedef long long ll;
bool arr[1000002];
int main()
{
	ll a, b;
	scanf("%lld %lld", &a, &b);
	int ans = b - a + 1;

	for (ll i = 2; i*i <= b; i++)
	{
		ll sq = i * i;
		ll temp = a / sq + (a % sq != 0);
		temp = temp * sq - a;

		while (temp <= b - a)
		{
			if (!arr[temp])
				ans--, arr[temp] = true;

			temp += sq;
		}

	}
	printf("%d", ans);

}
