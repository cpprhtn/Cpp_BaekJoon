#include<cstdio>

int main()
{
	int a;
	int max = 0, min = 100000;
	scanf("%d", &a);

	for(int i = 0; i < a; i++)
	{
		int temp;
		scanf("%d",&temp);
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}
	printf("%d %d",min, max);
}