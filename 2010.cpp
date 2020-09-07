#include <cstdio>

using namespace std;
int main()
{
	int num;
	int sum = 0, tab;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &tab);
		sum += tab;
	}

	printf("%d\n", sum - num + 1);
	return 0;
}