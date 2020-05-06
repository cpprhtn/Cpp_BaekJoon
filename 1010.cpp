#include<cstdio>

using namespace std;

int main()
{
	int no_case;
	scanf("%d", &no_case);
	while (no_case--)
	{
		long long n, m, p = 1, f = 1, ans;
		scanf("%lld %lld", &n, &m);
		if (m < n * 2)
			n = m - n;
		for (int i = 0; i < n; i++)
		{
			p *= m - i;
			f *= (i+1);
		}

		ans = p / f;
		printf("%lld\n", ans);
	}
	return 0;

}
