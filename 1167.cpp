#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<vector<pair<int, int> > > adj;
vector<int> d;
int n;

int bfs(int a)
{
    int max=0;
    vector<bool> v(n+1);
    queue<int> Q;
    v[a]=true, d[a]=0;
    Q.push(a);
    while(!Q.empty())
    {
        int pos=Q.front();
        Q.pop();
        for(auto i : adj[pos])
            if(!v[i.first])
            {
                v[i.first]=true, d[i.first]=d[pos]+i.second;
                Q.push(i.first);
                if(d[max]<d[i.first])
                    max=i.first;
            }

    }
    return max;
}
int main()
{
    scanf("%d", &n);
    adj.resize(n+1), d.resize(n+1);
    for(int i=0; i<n; i++)
    {
        int s, e, c;
        scanf("%d", &s);
        while(1)
        {
            scanf("%d", &e);
            if(e==-1)
                break;

            scanf("%d", &c);
            adj[s].push_back({e, c});
            adj[e].push_back({s, c});
        }
    }
    printf("%d", d[bfs(bfs(1))]);
}
