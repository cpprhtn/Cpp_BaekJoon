#include <cstdio>

int main()
{
	int a=0, b=0, count_a=0, count_b=0;
	char c;
	while(scanf("%c", &c)!=EOF)
	{
		c=='A'?count_a++:count_b++;
		if(count_a==21 || count_b==21)
		{
			printf("%d-%d\n", count_a, count_b);
			count_a>count_b?a++:b++;

			if(a==2 || b==2)
			{
				printf("%c", (a==2?'A':'B'));
				break;
			}
			count_a=count_b=0;
		}
	}
}
