#include <cstdio>

int main()
{
	int n, sum=0;
	int arr[20][20], visit[20][20]={};

	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &arr[i][j]), sum+=arr[i][j];

	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(arr[i][j]>arr[i][k]+arr[k][j])
				{
					printf("-1");
					return 0;
				}

				else if(k!=i && k!=j && !visit[i][j] && arr[i][j]==arr[i][k]+arr[k][j])
				{
					sum-=arr[i][j];
					visit[i][j]=1;
				}
			}
		}
	}

	printf("%d", sum/2);

}
