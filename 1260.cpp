#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
bool v[1001];
void dfs(int x)
{
	v[x] = 1;
	printf("%d ", x);
	sort(adj[x].begin(), adj[x].end());
	for (int i : adj[x])
		if (!v[i]) dfs(i);
}

void bfs(int x)
{
	queue<int> Q;
	bool v[1001] = {};
	Q.push(x);
	v[x] = 1;
	while (Q.size())
	{
		printf("%d ", x = Q.front());
		Q.pop();
		for (int i : adj[x])
			if (!v[i]) Q.push(i), v[i] = 1;
	}
}
int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(v);
	printf("\n");
	bfs(v);
}
