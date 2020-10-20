#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	char str[101];
	
	scanf("%s", str);
	for (int i = 0; i < 26; i++)
	{
		int pos = find(str, str + strlen(str), i + 'a') - str;
		if (pos == strlen(str))
			pos = -1;

		printf("%d ", pos);
	}

	return 0;
}
