#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int delarr[9] = {};

void delete_2()
{
	for (int i = 0; i < 7; i++)
	{
		delarr[i] = delarr[i + 2];
	}

}

int main()
{
	int arr[9] = {};
	int remainder = -100;
	int break_count = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		remainder += arr[i];
	}

	for (int x = 0; x < 9; x++)
	{
		for (int y = x + 1; y < 9; y++)
		{
			if (arr[x] + arr[y] == remainder)
			{
				delarr[0] = arr[x];
				delarr[1] = arr[y];
				break_count++;
				break;
			}
		}

		if (break_count == 1)
			break;
	}

	int ctr = 2;

	for (int i = 0; i < 9; i++)
	{

		if (arr[i] == delarr[0] || arr[i] == delarr[1])
		{
			continue;
		}

		delarr[ctr] = arr[i];
		ctr++;
	}

	delete_2();

	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (delarr[j] < delarr[i])
			{
				int temp = delarr[i];
				delarr[i] = delarr[j];
				delarr[j] = temp;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", delarr[i]);
	}
}