#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int countDiv(ll num, int d)
{
	int count = 0;
	for (int i = 1; 1; i++)
	{
		ll div = (ll)pow(d, i);
		if (div > num)
			return count;

		count += num / div;
	}

}
int main()
{
	int no2 = 0, no5 = 0;
	ll n, m;
	scanf("%lld %lld", &n, &m);
	if (m < n - m)
		m = n - m;

	if (m == 0)
	{
		printf("0");
		return 0;
	}
	no5 = countDiv(n, 5) - countDiv(m, 5) - countDiv(n - m, 5);
	no2 = countDiv(n, 2) - countDiv(m, 2) - countDiv(n - m, 2);
	printf("%d", no5 < no2 ? no5 : no2);
}
