#include<cstdio>

int main()
{
	bool arr[246913] = {};
	int n;
	for (int i = 2; i <= 246912; i++)
	{
		if (!arr[i])
		{
			int temp = i;
			while ((temp+=i) <= 246912)
				arr[temp] = true;
		}
	}
	while (scanf("%d", &n) && n)
	{
		int as = n * 2, count=0;
		for (int i = n+1; i <= as; i++)
			if (!arr[i])
				count++;

		printf("%d\n", count);
	}
}