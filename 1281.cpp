#include<cstdio>
#include<vector>
#include<cmath>
#define INF 1010101010
#define min(x, y) (x<y?x:y)
using namespace std;


int main()
{
	int a, b, m=INF, ans=0;
	vector<int> prime;

	scanf("%d %d", &a, &b);
	if (a < 2)
		a = 2;
	for (int i = a; i <= b; i++)
	{
		int j;
		for (j = 2; j <= sqrt(i); j++)
			if (!(i%j))
				break;

		if(j>sqrt(i))
			m = min(m, i), ans += i;
	}

	if (m == INF)
		printf("-1");

	else
		printf("%d\n%d\n", ans, m);
}