#include <cstdio>

int main()
{
	int num, temp;
	scanf("%d", &num);
	while (scanf("%d", &temp) != EOF)
	{
		num += temp;
		if (temp < 0)
			break;
	}
	while (scanf("%d", &temp) != EOF)
		num += (temp > 0 ? -temp : temp);

	printf("%d", num);
}