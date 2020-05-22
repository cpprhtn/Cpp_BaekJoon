#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int ans = 1, s, m, n;
	scanf("%d", &n);
	for (int i = 1; 1; i++)
	{
		if (ans + i > n)
		{
			m = i;
			break;
		}
		ans += i;
	}

	s = n - ans+1;
	if (m % 2)
		swap(s, m), s -= m - 1;

	else
		m -= s - 1;
	printf("%d/%d", s, m);
}