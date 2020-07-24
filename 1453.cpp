#include <cstdio>

int arr[101];
int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	while (n--)
	{
		register int num;
		scanf("%d", &num);
		if (arr[num])
			ans++;
		else
			arr[num] = 1;
	}

	printf("%d", ans);
}
