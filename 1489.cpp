#include <bits/stdc++.h>
const int INF=0x3f3f3f3f;
using namespace std;

struct edge{int v, f, c, rvs;};
int n;
int a[1001], b[1001], p[2002];
edge *path[2002];
int d[2002];
bool v[2002];
vector<edge> adj[2002];
void connect_edge(int a, int b, int f, int c)
{
    edge e1={b, f, c, adj[b].size()};
    edge e2={a, 0, -c, adj[a].size()};
    adj[a].push_back(e1);
    adj[b].push_back(e2);
}
bool spfa()
{
    memset(d, INF, sizeof(d));
    queue<int> Q;
    Q.push(0);
    d[0]=0;
    while(Q.size())
    {
        int cur=Q.front();
        v[cur]=0;
        Q.pop();
        for(auto &e : adj[cur])
        {
            auto &[next, flow, cost, rvs]=e;
            if(flow<=0 || d[next]<=d[cur]+cost) continue;
            d[next]=d[cur]+cost;
            p[next]=cur;
            path[next]=&e;
            if(!v[next])
            {
                Q.push(next);
                v[next]=1;
            }
        }
    }

    return d[2001]!=INF;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        connect_edge(0, i, 1, 0);
    }

    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        connect_edge(i+1000, 2001, 1, 0);
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i]>b[j]) connect_edge(i, j+1000, 1, -2);
            else if(a[i]==b[j]) connect_edge(i, j+1000, 1, -1);
            else connect_edge(i, j+1000, 1, 0);
        }
    }
    int ans=0;
    while(spfa())
    {
        ans-=d[2001];
        for(int i=2001; i; i=p[i])
        {
            path[i]->f--;
            adj[path[i]->v][path[i]->rvs].f++;
        }
    }

    cout<<ans;
}

