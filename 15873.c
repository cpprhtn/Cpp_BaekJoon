#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char arr[1000] = {};
	int sum = 0;
	scanf("%s", arr);

	int len = strlen(arr);


	for (int i = 0; i < len; i++)
	{
		arr[i] -= '0';
	}


	if (len == 2)
	{
		sum = arr[0] + arr[1];
	}

	else if (len == 3)
	{
		if (arr[0] == 1)
		{
			if (arr[1] == 0)
			{
				sum = 10 + arr[2];
			}
			else
			{
				sum = 11;
			}
		}

		else
		{
			sum = arr[0] + 10;
		}
	}

	else
	{
		sum = 20;
	}

	printf("%d", sum);
}