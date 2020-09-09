#include<stdio.h>

int main()
{
	int n, k, a=0;
	scanf("%d", &n);

	while(scanf("%d", &k)!=EOF)
		a+=k;

	printf("Junhee is %s", (a>n-a?"cute!":"not cute!"));
}
