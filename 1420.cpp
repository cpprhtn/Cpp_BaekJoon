#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
const int dx[]={0, 0, 1, -1};
const int dy[]={1, -1, 0, 0};
int sx, sy, ex, ey;
const int MAX = 20005;
struct Edge{
    int v, cap, rev;
    Edge(){}
    Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev){}
};
int N, M, S, T, level[MAX], work[MAX];
vector<Edge> adj[MAX];

bool bfs(){
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(S);  level[S] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto &i : adj[cur]){
            int next = i.v;
            int cap = i.cap;
            if(cap > 0 && level[next] == -1){
                level[next] = level[cur] + 1;
                q.push(next);
            }
        }
    }
    return level[T] != -1;
}

int dfs(int cur, int flow){
    if(cur == T)    return flow;
    for(int &i = work[cur]; i < adj[cur].size(); i++){
        int next = adj[cur][i].v;
        int cap = adj[cur][i].cap;
        int rev = adj[cur][i].rev;
        if(cap > 0 && level[next] == level[cur] + 1){
            int cf = dfs(next, min(flow, cap));
            if(cf > 0){
                adj[cur][i].cap -= cf;
                adj[next][rev].cap += cf;
                return cf;
            }
        }
    }
    return 0;
}

int solve(){
    int ret = 0;
    while(bfs()){
        memset(work, 0, sizeof(work));
        while(true){
            int flow = dfs(S, 1e9);
            if(flow == 0)break;
            ret += flow;
        }
    }
    return ret;
}

void addEdge(int u, int v, int cap){
    adj[u].emplace_back(v, cap, adj[v].size());
    adj[v].emplace_back(u, 0, adj[u].size() - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j]=='K')
                sx=i, sy=j;

            else if(arr[i][j]=='H')
                ex=i, ey=j;

            else if(arr[i][j]=='#') continue;

            addEdge(10000+i*100+j, i*100+j, 1);
            for(int k=4; k--;)
            {
                int nx=i+dx[k], ny=j+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m || arr[nx][ny]=='#') continue;
                addEdge(i*100+j, 10000+nx*100+ny, 1);
            }

        }
    }

    for(int k=4; k--;)
    {
        int nx=sx+dx[k], ny=sy+dy[k];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(arr[nx][ny]=='H')
        {
            cout<<-1;
            return 0;
        }
    }

    S=20002, T=20003;
    addEdge(S, sx*100+sy, 1e9);
    addEdge(10000+ex*100+ey, T, 1e9);
    cout<<solve();
}
