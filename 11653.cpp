#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	if (num == 1)
		return 0;
	for (int i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{
			printf("%d\n", i);
			num /= i;
			i = 1;
		}
	}
}