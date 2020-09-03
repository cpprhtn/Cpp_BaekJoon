#include <cstdio>

int main()
{
	int n, x;
	scanf("%d", &x);
	while(1)
	{
		scanf("%d", &n);
		if(n==0) return 0;
		printf("%d is%sa multiple of %d.\n", n, (n%x?" NOT ":" "), x);
	}
}