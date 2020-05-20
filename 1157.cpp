#include <cstdio>
#include <cctype>
using namespace std;
int main()
{
	int m[27]={};
	int ans=0;
	char a=0;
	bool s=true;
	while(1)
	{
		scanf("%c", &a);
		if(a=='\n')
			break;
		a=toupper(a)-'A';
		int max=m[ans];
		m[a]++;
		if(max==m[a])
			s=true;

		else if(max<m[a])
			ans=a, s=false;
	}

	if(s==true)
		printf("?\n");

	else
		printf("%c\n", ans+'A');

	return 0;
}
