#include <cstdio>

int arr[51];

int main()
{
	int n, ans;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	if(n==1)
	{
		puts("A");
		return 0;
	}
	if(n==2)
	{
		if(arr[0]!=arr[1]) puts("A");
		else printf("%d", arr[0]);
		return 0;
	}
	
	if(arr[0]==arr[1])
	{
		if(arr[1]!=arr[2])
		{
			puts("B");
			return 0;
		}
		else
		{
			int x=arr[0];
			for(int i=3; i<n; i++)
			{
				if(arr[i]!=x)
				{
					puts("B");
					return 0;
				}
			}
			printf("%d", arr[0]);
		}
		
	}
	else
	{
		float a=float(arr[1]-arr[2])/float(arr[0]-arr[1]);
		float b=float(arr[1]*arr[1]-arr[0]*arr[2])/float(arr[1]-arr[0]);
		if(a!=int(a) || b!=int(b))
		{
			puts("B");
			return 0;
		}

		for(int i=3; i<n; i++)
		{
			if(arr[i-1]*int(a)+int(b)!=arr[i])
			{
				puts("B");
				return 0;
			}
		}

		printf("%d", arr[n-1]*int(a)+int(b));
	}
	
}