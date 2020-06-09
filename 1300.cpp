#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin>>n>>k;

    long long l=1, r=k;

    while(l<=r)
    {
        long long ln=0, sn=0, mid=(l+r)>>1;

        for(int i=1; i<=n; i++)
        {
            if(mid/i<=n && mid%i==0) sn++;
            ln+=min(mid/i, n);
        }

        if(ln>=k && ln-sn<k)
        {
            cout<<mid;
            return 0;
        }
        if(ln<k) l=mid+1;
        else r=mid-1;
    }
}