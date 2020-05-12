#include <cstdio>

int main()
{
	int n, m, count=0;
	char A[50][51], B[50][51];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", A[i]);

	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (A[i][j] != B[i][j])
			{
				count++;
				for (int k = i; k < i + 3; k++)
				{
					for (int l = j; l < j + 3; l++)
					{
						A[k][l] = (A[k][l] == '0' ? '1' : '0');
					}
				}

			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] != B[i][j])
			{
				printf("-1");
				return 0;
			}
		}
	}

	printf("%d", count);
}
