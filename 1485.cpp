#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
ll getDist(pair<ll, ll> &a, pair<ll, ll> &b)
{
	ll dx = (a.first - b.first)*(a.first - b.first);
	ll dy= (a.second - b.second)*(a.second - b.second);
	return dx + dy;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		map<ll, int> dist;
		pair<ll, ll> arr[4];
		for (int i = 0; i < 4; i++)
		{
			ll x, y;
			scanf("%lld %lld", &x, &y);
			arr[i] = { x, y };
		}

		for (int i = 0; i < 3; i++)
			for (int j = i + 1; j < 4; j++)
				dist[getDist(arr[i], arr[j])]++;

		printf("%d\n", (dist.begin()->second == 4 && (++dist.begin())->second == 2));

	}

}