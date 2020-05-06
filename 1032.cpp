#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int no_case;
	char temp[51], ans[51];
	scanf("%d", &no_case);
	scanf("%s", ans);

	for (int i = 1; i < no_case; i++)
	{
		scanf("%s", temp);
		for (int j = 0; j < strlen(ans); j++)
			if (temp[j] != ans[j])
				ans[j] = '?';

	}

	printf("%s\n", ans);
	return 0;
}