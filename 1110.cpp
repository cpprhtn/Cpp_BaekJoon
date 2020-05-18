#include <cstdio>

int main()
{
	int num, temp, count=0;
	scanf("%d", &num);
	temp = num;
	do
	{
		int a = temp / 10, b = temp % 10;
		temp = b * 10 + (a + b) % 10;
		count++;
	} while (temp != num);

	printf("%d\n", count);
}