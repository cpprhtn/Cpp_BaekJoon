#include <bits/stdc++.h>
#define MAX 1011
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
	int v, f, c;
	edge *rvs;
	edge(int _v, int _f, int _c) : v(_v), f(_f), c(_c), rvs(0){}
};
int n, a, b, S, A, B, E;
vector<edge*> adj[MAX];
int p[MAX], d[MAX];
edge *path[MAX];
bool inQ[MAX];
void connect_edge(int s, int e, int f, int c)
{
	edge *e1, *e2;
	e1=new edge(e, f, c);
	e2=new edge(s, 0, -c);
	e1->rvs=e2, e2->rvs=e1;
	adj[s].push_back(e1);
	adj[e].push_back(e2);
}

bool spfa()
{
	queue<int> Q;
	memset(d, INF, sizeof(d));
	d[S]=0;
	Q.push(S);
	while(Q.size())
	{
		int cur=Q.front();
		Q.pop();
		inQ[cur]=0;

		for(edge *e : adj[cur])
		{
			int next=e->v, f=e->f, c=e->c;
			if(f>0 && d[next]>d[cur]+c)
			{
				d[next]=d[cur]+c;
				path[next]=e;
				p[next]=cur;
				if(!inQ[next]) inQ[next]=1, Q.push(next);
			}
		}
	}

	return d[E]!=INF;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
	while(1)
	{
		cin>>n>>a>>b;
		if(n==0) return 0;
		S=n+1, A=n+2, B=n+3, E=n+4;
		connect_edge(S, A, a, 0);
		connect_edge(S, B, b, 0);
		for(int i=1; i<=n; i++)
		{
			int k, da, db;
			cin>>k>>da>>db;
			connect_edge(A, i, INF, da);
			connect_edge(B, i, INF, db);
			connect_edge(i, E, k, 0);
		}

		int ans=0;
		while(spfa())
		{
			int min_flow=INF;
			for(int i=E; i!=S; i=p[i])
			{
				min_flow=min(min_flow, path[i]->f);
			}

			for(int i=E; i!=S; i=p[i])
			{
				ans+=path[i]->c*min_flow;
				path[i]->f-=min_flow;
				path[i]->rvs->f+=min_flow;
			}
		}

		cout<<ans<<"\n";
		for(int i=1; i<=n+4; i++)
		{
			for(auto &i : adj[i])
				delete i;

			adj[i].clear();
		}
	}
}