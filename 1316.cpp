#include<cstdio>
#include<map>

using namespace std;
int main()
{
	int t, ans=0;
	scanf("%d", &t);

	while (t--)
	{
		char str[101];
		map<char, int> M;
		scanf("%s", str);

		M[str[0]]++;
		int i = 1;
		for (; *(str + i); i++)
		{
			if (str[i] != str[i - 1] && M[str[i]])
				break;

			M[str[i]]++;
		}

		if (!str[i])
			ans++;
	}

	printf("%d\n", ans);
}