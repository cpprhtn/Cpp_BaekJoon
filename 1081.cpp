#include <cstdio>
#include <cmath>

typedef long long ll;
ll solve(ll x)
{
	ll m=1, num=0, ans=0;
	while(x)
	{
		ll cur=x%10;
		x/=10;

		for(int i=1; i<10; i++)
		{
			if(i<cur)
				ans+=i*(x+1)*m;

			else if(i==cur)
				ans+=i*((x*m)+(num+1));

			else
				ans+=i*x*m;
		}

		num+=cur*m, m*=10;
	}

	return ans;
}
int main()
{
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", solve(b)-solve(a-1));
}
