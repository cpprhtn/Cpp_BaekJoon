#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

char arr[50][51];
bool v[50][50];
int n, m;
int dp[50][50];

int solve(int x, int y, int c)
{
    if(dp[x][y]!=-1) return dp[x][y];
    if(v[x][y]) 
    {
        cout<<-1;
        exit(0);
    }
    v[x][y]=1;
    int ret=0, cur=arr[x][y]-'0';
    
    for(int i=4; i--;)
    {
        int nx=x+cur*dx[i], ny=y+cur*dy[i];
        if(nx<0 || nx>=n ||ny<0 || ny>=m || arr[nx][ny]=='H') continue;
        ret=max(ret, solve(nx, ny, c+1)+1);
    }

    v[x][y]=0;
    return dp[x][y]=ret;
}
int main()
{
    cin>>n>>m;
    memset(dp, -1, 4*50*n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<solve(0, 0, 0)+1;
}