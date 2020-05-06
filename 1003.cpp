#include <cstdio>

int main()
{
	int z[41] = { 1, };
	int o[41] = { 0, 1, };

	for (int i = 2; i <= 40; i++)
	{
		z[i] = z[i - 2] + z[i - 1];
		o[i] = o[i - 2] + o[i - 1];
	}

	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d %d\n", z[n], o[n]);
	}
}