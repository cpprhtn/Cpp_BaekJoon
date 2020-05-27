#include <cstdio>
#include <algorithm>
#define INF 6000000
#define max(x, y) (x>y?x:y)
using namespace std;

int main()
{
	int adj[1001][1001]={};
	int n, m, x, ans=0;
	scanf("%d %d %d", &n, &m, &x);

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			adj[i][j]=INF;

		adj[i][i]=0;
	}

	while(m--)
	{
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);
		if(adj[s][e]>c)
			adj[s][e]=c;
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(adj[i][j]>adj[i][k] + adj[k][j])
					adj[i][j]=adj[i][k] + adj[k][j];

	for(int i=1; i<=n; i++)
		ans=max(ans, adj[i][x]+adj[x][i]);

	printf("%d\n", ans);
	return 0;
}
