#include <cstdio>
#include <vector>
using namespace std;

vector<long long> dp;
long long fibo(int n)
{
	for(int i=dp.size(); i<=n; i++)
		dp.push_back(dp[i-1]+dp[i-2]);

	return dp[n];
}
int main()
{
	dp.push_back(0);
	dp.push_back(1);
	int num;
	scanf("%d", &num);
	printf("%lld\n", fibo(num));
}
