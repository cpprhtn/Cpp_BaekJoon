#include <cstdio>
#include <set>
using namespace std;
int main()
{
	int n;
	set<char> S;
	int arr[26] = {};
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char str[31];
		scanf("%s", str);
		arr[str[0] - 'a']++;
		if (arr[str[0] - 'a'] == 5)
			S.insert(str[0]);
	}

	if (S.empty())
	{
		printf("PREDAJA");
	}

	else
	{
		for (auto ch : S)
			printf("%c", ch);
	}
}