#include <bits/stdc++.h>
using namespace std;

int n;
bool chk[40][40];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
double p[4];
double solve(int c, int x, int y)
{
    if(chk[x][y]) return 0;
    if(c==n) return 1;

    chk[x][y]=1;
    double ret=0;
    for(int i=4; i--;)
    {
        int nx=x+dx[i], ny=y+dy[i];
        ret+=p[i]*solve(c+1, nx, ny);
    }

    chk[x][y]=0;
    return ret/100;
}
int main()
{
    cin>>n;
    
    for(int i=0; i<4; i++)
        cin>>p[i];

    cout.precision(11);
    cout<<solve(0, 15, 15);
}