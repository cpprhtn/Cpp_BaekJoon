#include<cstdio>
#define min(x, y) (x<y?x:y)
using namespace std;
int main()
{
	long long dp[3][2]={};
	int n;
	scanf("%d", &n);
	while(n--)
	{
		long long r, g, b;
		scanf("%lld %lld %lld", &r, &g, &b);
		dp[0][1]=min(dp[1][0], dp[2][0])+r;
		dp[1][1]=min(dp[0][0], dp[2][0])+g;
		dp[2][1]=min(dp[0][0], dp[1][0])+b;
		dp[0][0]=dp[0][1], dp[1][0]=dp[1][1], dp[2][0]=dp[2][1];
	}

	printf("%lld", min(min(dp[0][0], dp[1][0]), dp[2][0]));
	return 0;
}
