#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[20][100001], d[100001];
bool v[100001];
void dfs(int cur)
{
    v[cur]=1;
    for(int next : adj[cur])
    {
        if(!v[next])
        {
            p[0][next]=cur;
            d[next]=d[cur]+1;
            dfs(next);
        }
    }
}

int lca(int a, int b)
{
    if(d[a]>d[b]) swap(a, b);
    int diff=d[b]-d[a];
    for(int i=20; i--;)
    {
        if(diff & (1<<i)) b=p[i][b];
    }

    if(a==b) return a;
    for(int i=20; i--;)
    {
        if(p[i][a] != p[i][b]) a=p[i][a], b=p[i][b];
    }

    return p[0][a];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin>>n;

    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    for(int i=1; i<20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }

    cin>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        cout<<lca(a, b)<<'\n';
    }
}