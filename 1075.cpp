#include<cstdio>
using namespace std;

int main()
{
	long long n, f;
	scanf("%lld %lld", &n, &f);

	n -= (n % 100);

	if (n%f == 0)
		printf("00\n");

	else
		printf("%02lld\n", f - (n%f));
}