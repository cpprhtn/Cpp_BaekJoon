#include <bits/stdc++.h>
using namespace std;

int n;;
vector<int> A, B;
int arr[20][20];
int func(int p)
{
    if(n==p) 
    {
        int a=0, b=0;
        for(int i=0; i<A.size(); i++)
        {
            for(int j=i+1; j<A.size(); j++)
            {
                a+=arr[A[i]][A[j]]+arr[A[j]][A[i]];
            }
        }

        for(int i=0; i<B.size(); i++)
        {
            for(int j=i+1; j<B.size(); j++)
            {
                b+=arr[B[i]][B[j]]+arr[B[j]][B[i]];
            }
        }
        return abs(a-b);
    }
    A.push_back(p);
    int ret=func(p+1);
    A.pop_back();
    B.push_back(p);
    ret=min(ret, func(p+1));
    B.pop_back();
    return ret;    
}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<func(0);
}