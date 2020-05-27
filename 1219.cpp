#include <iostream>
#include <vector>
#include <queue>
#define INF 1111111111
#define CYCLE -111111111
using namespace std;

struct edge
{
	int v, c;
};

vector<edge> adj[100];
queue<int> Q;
int dist[100], earn[100], intoQ[100] = {};
int n, m, s, e;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bool isRoop = false;
	cin >> n >> s >> e >> m;

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		adj[a].push_back({ b, c });
	}

	for (int i = 0; i < n; i++)
		cin >> earn[i];

	Q.push(s);
	dist[s] = -earn[s];

	int update = 0;
	while (Q.size() && update<n+100)
	{
		update++;
		int cur = Q.front();
		Q.pop(), intoQ[cur]=0;

		for (auto &next : adj[cur])
		{
			if (dist[next.v] > dist[cur] + next.c - earn[next.v])
			{
				dist[next.v] = (update >= n ? CYCLE : dist[cur] + next.c - earn[next.v]);
				if (!intoQ[next.v])
					Q.push(next.v), intoQ[next.v] = 1;
			}
		}

	}

	if (dist[e] == INF)
		printf("gg");

	else if (dist[e]==CYCLE)
		printf("Gee");

	else
		printf("%d", -dist[e]);
}