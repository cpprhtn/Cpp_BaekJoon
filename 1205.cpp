#include <iostream>
using namespace std;

int arr[52];
int main()
{
    int n, m, p;
    cin>>n>>m>>p;

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    if(p==n && arr[n]>=m) cout<<-1;
    else
    {
        for(int i=1; i<=p; i++)
        {
            if(arr[i]<=m)
            {
                cout<<i;
                return 0;
            }
        }
    }
    
}