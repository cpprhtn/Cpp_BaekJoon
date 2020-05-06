#include <cstdio>
#include <cmath>

int arr[10];
int main()
{
	int n, m=1, num=0;

	scanf("%d", &n);
	while(n)
	{
		int cur=n%10;
		n/=10;
		if(n)
			arr[0]-=m;
		for(int i=0; i<10; i++)
		{
			if(i<cur && !(!n && !i))
				arr[i]+=(n+1)*m;

			else if(i==cur)
				arr[i]+=(n*m)+(num+1);

			else
				arr[i]+=n*m;
		}

		num+=cur*m, m*=10;
	}

	for(int i=0; i<10; i++)
		printf("%d ", arr[i]);
}
