#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		char str[21];
		scanf("%d %s", &n, str);
		for(int i=0; str[i]; i++)
			for(int j=0; j<n; j++)
				printf("%c", str[i]);

		printf("\n");
	}

}
