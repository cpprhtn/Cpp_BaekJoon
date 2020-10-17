#include<cstdio>

int main()
{
	int n = 0;
	int max = -1;
	int count;

	for(int i = 0; i < 9; i++)
	{
		scanf("%d",&n);
		if (n > max) {
			max = n;
			count = i+1;
		}
	}
	printf("%d\n%d",max, count);
}