#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, max=0;
	scanf("%d", &n);
	int *k=new int[n+1], *s=new int[n+1];

	for (int i = 0; i<n; i++)
		scanf("%d", &k[i]), s[i] = k[i];

	sort(s, s+n);
	for (int i = n - 1; i >= 0; i--)
	{
		auto pos = upper_bound(s, s+n, k[i])-1;
		if (max < i - (pos-s))
			max = i - (pos-s);

		*pos = -1;

	}

	printf("%d", max+1);
	delete[]k;
	delete[]s;
	return 0;
}