#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[200001];
bool visit[200001];
int main()
{
	int n, l, x, s, d, ans = -1;
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= l; i++)
	{
		while (1)
		{
			scanf("%d", &x);
			if (x == -1)
				break;

			adj[x].push_back(n + i);
			adj[n + i].push_back(x);
		}
	}

	scanf("%d %d", &s, &d);
	queue<int> Q;
	Q.push(s);
	visit[s] = 1;
	while (Q.size())
	{
		int cur_size = Q.size();

		if (Q.front() > n)
			ans++;

		while(cur_size--)
		{
			int cur = Q.front();
			Q.pop();
			if (cur == d)
			{
				printf("%d", ans < 0 ? 0 : ans);
				return 0;
			}


			for (int i : adj[cur])
			{
				if (!visit[i])
					Q.push(i), visit[i] = 1;
			}
		}
	}

	printf("-1");
}