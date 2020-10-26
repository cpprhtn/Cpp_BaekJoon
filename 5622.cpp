#include <stdio.h>
int main()
{
	char str[16], x;
	int ans=0;
	scanf("%s", str);

	for(int i=0; str[i]; i++)
	{
		if(str[i]=='Z')
			str[i]--;
		if(str[i]>='S')
			str[i]--;

		ans+=(str[i]-'A')/3+3;
	}

	printf("%d", ans);
}
