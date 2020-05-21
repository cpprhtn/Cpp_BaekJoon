#include <cstdio>

int arr[20];
int n, s;

int solve(int it, int x)
{
	if (it == n)
		return x == s;

	return solve(it + 1, x) + solve(it + 1, x + arr[it]);
}
int main()
{
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int ans = solve(0, 0);
	printf("%d", ans - (s == 0));
}