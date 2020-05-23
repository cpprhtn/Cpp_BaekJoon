#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int v, e, count, visit[10001]={};
	vector<pair<int, long long> > adj[10001];
	long long ans=0;

	scanf("%d %d", &v, &e);
	while(e--)
	{
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);

		adj[a].push_back({-c, b});
		adj[b].push_back({-c, a});
	}

	priority_queue<pair<int, long long> > pq;
	int cur=1;
	visit[1]=1, count=v-1;
	while(count--)
	{
		for(auto &i : adj[cur])
			if(!visit[i.second])
				pq.push(i);

		while(pq.size())
		{
			cur=pq.top().second;
			if(!visit[cur])
			{
				ans-=pq.top().first;
				visit[cur]=1;
				pq.pop();
				break;
			}
			pq.pop();
		}
	}

	printf("%lld", ans);
}
