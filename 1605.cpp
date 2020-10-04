#include <bits/stdc++.h>
#define MOD 100007
using namespace std;

unsigned long long d[200001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str;
    cin>>n>>str;
    int l=1, r=n-1, aa=0;
    d[0]=1;
    for(int i=1; i<=n; i++)
        d[i]=d[i-1]*7;

    while(l<=r)
    {
        int mid=l+r>>1;
        unsigned long long hash=0;
        vector<vector<unsigned long long> >hash_map(MOD);
        for(int i=0; i<mid; i++)
        {
            hash*=7;
            hash+=str[i];
        }

        hash_map[hash%MOD].push_back(hash);
        
        for(int i=mid; i<n; i++)
        {
            hash-=str[i-mid]*d[mid-1];
            hash=hash*7+str[i];
            for(unsigned long long &j : hash_map[hash%MOD])
            {
                if(j==hash)
                {
                    l=mid+1;
                    aa=max(aa, mid);
                    i=n;
                    break;
                }
            }
            if(i==n-1)
            {
                r=mid-1;
            }

            hash_map[hash%MOD].push_back(hash);
        }
        
    }

    cout<<aa;
}