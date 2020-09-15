#include <cstdio>

long long arr[21];
bool solve(int it, long long x)
{
	if (it == -1 || x <= 0) return x == 0;
	if (solve(it - 1, x - arr[it])) return true;
	return solve(it - 1, x);
}
int main()
{
	arr[0] = 1;
	for (int i = 1; i <= 20; i++)
		arr[i] = arr[i - 1] * i;

	long long n;
	scanf("%lld", &n);
	if (n == 0) puts("NO");
	else puts(solve(20, n) ? "YES" : "NO");
}
