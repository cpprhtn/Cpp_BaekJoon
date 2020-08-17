#include <iostream>
#include <vector>
#include <queue>
#define MAX 501
using namespace std;

vector<int> adj[MAX];
int in[MAX], t[MAX], ans[MAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, p;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		while (1)
		{
			cin >> p;
			if (p == -1) break;
			adj[p].push_back(i);
			in[i]++;
		}
	}

	priority_queue<pair<int, int> > pq;
	for (int i = 1; i <= n; i++)
		if (!in[i]) pq.push({ -t[i], i });

	while (pq.size())
	{
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		ans[cur] = cost;

		for (int i : adj[cur])
		{
			if (!--in[i]) pq.push({ -cost - t[i], i });
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << "\n";
}