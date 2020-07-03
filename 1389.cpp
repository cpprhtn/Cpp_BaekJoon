#include <cstdio>
#include <algorithm>
#define INF 6000000
using namespace std;

int main()
{
	int adj[101][101]={};
	int n, m, ans=0;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			adj[i][j]=INF;

		adj[i][i]=0;
	}

	while(m--)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s][e]=adj[e][s]=1;
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(adj[i][j]>adj[i][k] + adj[k][j])
					adj[i][j]=adj[i][k] + adj[k][j];

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			adj[0][i]+=adj[i][j];

	}

	printf("%d\n", min_element(adj[0]+1, adj[0]+n+1)-adj[0]);
	return 0;
}
