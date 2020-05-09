#include<stdio.h>
int main()
{
	int n, ans=99;
	scanf("%d", &n);
	if(n<100)
	{
		printf("%d", n);
		return 0;
	}

	if(n==1000)
		n--;
	for(int i=100; i<=n; i++)
	{
		int a, b, c;
		a=i%10;
		b=(i%100)/10;
		c=i/100;
		if(b-a==c-b)
			ans++;
	}
	printf("%d", ans);
}
