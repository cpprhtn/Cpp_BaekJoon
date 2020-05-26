#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	map<char, int> M;
	char str[51], find=0;
	int size;
	scanf("%s", str);
	size = strlen(str);
	for (int i = 0; str[i]; i++)
		M[str[i]]++;

	for (auto i : M)
	{
		if (i.second % 2)
		{
			if (find)
			{
				printf("I'm Sorry Hansoo");
				return 0;
			}

			else
				find = i.first;
		}
	}

	int pos = 0;
	for (auto i : M)
	{
		if (find == i.first)
		{
			str[size / 2] = find;
			i.second--;
		}

		for (int j = 0; j < i.second / 2; j++, pos++)
			str[pos] = str[size - pos - 1] = i.first;
	}

	printf("%s", str);
}