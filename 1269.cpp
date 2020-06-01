#include <cstdio>
#include <unordered_set>
using namespace std;

int main()
{
	int n, m, num, ans;
	unordered_set<int> S;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		S.insert(num);
	}

	ans = n;

	while (m--)
	{
		scanf("%d", &num);
		ans += (S.find(num)==S.end() ? 1 : -1);
	}

	printf("%d", ans);
}