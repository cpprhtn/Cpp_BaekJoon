#include <cstdio>
#define MOD 1000000
int arr[1000][2][3];
int main()
{
	int n;
	scanf("%d", &n);

	arr[0][0][0] = arr[0][1][0] = arr[0][0][1] = 1;

	for (int i = 1; i < n; i++)
	{
		arr[i][0][0] = arr[i - 1][0][0] + arr[i - 1][0][1] + arr[i - 1][0][2];
		arr[i][0][1] = arr[i - 1][0][0];
		arr[i][0][2] = arr[i - 1][0][1];
		arr[i][1][0] = arr[i - 1][0][0] + arr[i - 1][0][1] + arr[i - 1][0][2] + arr[i - 1][1][0] + arr[i - 1][1][1] + arr[i - 1][1][2];
		arr[i][1][1] = arr[i - 1][1][0];
		arr[i][1][2] = arr[i - 1][1][1];

		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 3; k++)
				arr[i][j][k] %= MOD;

	}

	int ans = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			ans += arr[n - 1][i][j];

	printf("%d", ans%MOD);
}