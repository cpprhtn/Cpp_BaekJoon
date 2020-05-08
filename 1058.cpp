#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int arr[50][50];
int main()
{
    int n;
    char str[51];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>str;
        for(int j=0; j<n; j++)
        {
            arr[i][j]=(str[j]=='Y'?1:INF);
        }
        arr[i][i]=0;
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j]>arr[i][k]+arr[k][j])
                {
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++)
    {
        int cur=0;
        for(int j=0; j<n; j++)
        {
            cur+=(arr[i][j]==1 || arr[i][j]==2);
        }
        ans=max(ans, cur);
    }
    cout<<ans;
}