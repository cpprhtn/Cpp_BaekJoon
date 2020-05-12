#include <cstdio>
using namespace std;

int main(void)
{
	int no_case;
	int a, b;
	scanf("%d", &no_case);
	for (int i = 1; i <= no_case; i++)
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	}

	return 0;
}
