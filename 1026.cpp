#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> a, b;
	int no_num, ans=0;
	scanf("%d", &no_num);
	a.resize(no_num), b.resize(no_num);
	for (int i = 0; i < no_num; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < no_num; i++)
		scanf("%d", &b[i]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < no_num; i++)
		ans += a[i] * b[no_num - i - 1];

	printf("%d\n", ans);
}
