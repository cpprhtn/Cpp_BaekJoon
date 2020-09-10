#include <cstdio>
#include <algorithm>

int main()
{
	long long n, arr[500001], ans=0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);

	std::sort(arr + 1, arr + n + 1);

	for (int i = 1; i <= n; i++)
		ans += abs(i - arr[i]);

	printf("%lld", ans);
}