#include <cstdio>
#include <cmath>

int solve(long long s, int n, int r, int c)
{
	if(n==1)
		return s+2*r+1*c;

	long long size=pow(2, n)/2;
	if(size<=r)
	{
		if(size<=c)
			return solve(s+pow(size, 2)*3, n-1, r-size, c-size);

		else
			return solve(s+pow(size, 2)*2, n-1, r-size, c);

	}
	else
	{
		if(size<=c)
			return solve(s+pow(size, 2), n-1, r, c-size);

		else
			return solve(s, n-1, r, c);

	}
}

int main()
{
	long long n;
	int r, c;
	scanf("%lld %d %d", &n, &r, &c);

	printf("%d", solve(0, n, r, c));
}
