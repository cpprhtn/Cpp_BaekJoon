#include<cstdio>

int main()
{
	bool arr[1000001] = {};
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 2; i <= n; i++)
	{
		if (!arr[i])
		{
			if (i >= m)
				printf("%d\n", i);

			int temp = i;
			while ((temp+=i) <= n)
				arr[temp] = true;
		}
	}
}