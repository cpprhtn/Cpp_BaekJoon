#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n, arr[11];
	vector<int> ans;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = n; i > 0; i--)
	{
		ans.insert(ans.begin() + arr[i], i);
	}

	for (auto i : ans)
		printf("%d ", i);
}