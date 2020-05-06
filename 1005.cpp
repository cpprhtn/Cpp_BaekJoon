#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adj;
vector<int> in, t;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	while (k--)
	{
		int n, m, w;
		cin >> n >> m;
		adj.resize(n + 1), in.assign(n + 1, 0), t.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> t[i];

		while (m--)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			in[b]++;
		}

		cin >> w;

		priority_queue<pair<int, int> > Q;
		for (int i = 1; i <= n; i++)
			if (in[i] == 0) Q.push({ -t[i], i });

		while (Q.size())
		{
			int cur = Q.top().second;
			int cost = -Q.top().first;
			Q.pop();
			if (cur == w)
			{
				cout << cost << "\n";
				break;
			}
			for (int i : adj[cur])
			{
				if (!--in[i])
					Q.push({ -cost - t[i], i });
			}
		}

		adj.clear(), in.clear(), t.clear();
	}
}