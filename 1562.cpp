#include <bits/stdc++.h>

using namespace std;
const int MOD=1e9;
int p[10][101][1<<10];
bool v[10][101][1<<10];
int n;
int solve(int x, int p, int h)
{
    if(v[x][p][h]) return p[x][p][h];
    if(p==1) return (h | (1<<x))==(1<<10)-1;
    v[x][p][h]=1;
    if(x!=0) p[x][p][h]=(p[x][p][h]+solve(x-1, p-1, h | (1<<x)))%MOD;
    if(x!=9) p[x][p][h]=(p[x][p][h]+solve(x+1, p-1, h | (1<<x)))%MOD;
    return p[x][p][h];
}
int main()
{
    cin>>n;
    int ans=0;
    for(int i=1; i<10; i++)
    {
        ans=(ans+solve(i, n, 0))%MOD;
    }
    
    cout<<ans;
}