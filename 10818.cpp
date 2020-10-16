#include<cstdio>

int main()
{
	int max=-1000001, min=1000001;
	int no_data, num;
	scanf("%d", &no_data);
	for(int i=0; i<no_data; i++)
	{
		scanf("%d", &num);
		max=num>max?num:max;
		min=num<min?num:min;
	}

	printf("%d %d\n", min, max);
	return 0;
}
