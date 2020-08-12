#include<cstdio>
#include<vector>
using namespace std;

const long long INF = 999999999;
const int MAX_NODE = 801;
int main()
{
	int no_node, no_edge, start, end, p1, p2;
	long long adj[MAX_NODE][MAX_NODE];
	long long edge;
	scanf("%d %d", &no_node, &no_edge);

	for (int i = 1; i <= no_node; i++)
	{
		for (int j = 1; j <= no_node; j++)
			adj[i][j] = INF;

		adj[i][i] = 0;
	}

	for (int i = 0; i < no_edge; i++)
	{
		scanf("%d %d %lld", &start, &end, &edge);
		if(adj[start][end]>edge)
			adj[end][start] = adj[start][end] = edge;


	}

	for (int k = 1; k <= no_node; k++)
		for (int i = 1; i <= no_node; i++)
			for (int j = 1; j <= no_node; j++)
				if (adj[i][k] + adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k] + adj[k][j];

	scanf("%d %d", &p1, &p2);

	long long ans1 = adj[1][p1] + adj[p1][p2] + adj[p2][no_node], ans2 = adj[1][p2] + adj[p2][p1] + adj[p1][no_node];
    if(ans1>=INF && ans2>=INF)
        printf("-1");

    else
	   printf("%lld\n", (ans1 > ans2 ? ans2 : ans1));
	return 0;
}
