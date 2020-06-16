#include <cstdio>
#define mod 9901
using namespace std;

int main()
{
	int dp1, dp2, dp0;
	int n;
	scanf("%d", &n);

	dp1=dp2=dp0=1;
	for(int i=2; i<=n; i++)
	{
		int a1, a2, a0;
		a1=dp2+dp0;
		a2=dp1+dp0;
		a0=dp1+dp2+dp0;
		dp1=a1%mod, dp2=a2%mod, dp0=a0%mod;
	}

	printf("%d\n", (dp1+dp2+dp0)%mod);
	return 0;
}
