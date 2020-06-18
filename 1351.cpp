#include<cstdio>
#include<map>
using namespace std;


map<long long, long long>M;
long long p, q;
long long func(long long n)
{
    if(!n)
        return 1;

    long long &MN=M[n];
    if(MN)
        return MN;

    MN=func(n/p)+func(n/q);
    return MN;
}
int main()
{
    long long n;
    M[0]=1;
    scanf("%lld %lld %lld", &n, &p, &q);
    printf("%lld", func(n));
}
