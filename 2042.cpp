#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
typedef long long ll;

ll pt[MAX + 1];
ll arr[MAX + 1];
int n, m, k;
void update(int p, ll x)
{
	ll h = arr[p];
	arr[p] = x;
	while (p <= n)
	{

		pt[p] += x - h;
		p += (p&-p);
	}

}

ll query(int p)
{
	ll ret = 0;
	while (p)
	{
		ret += pt[p];
		p -= (p&-p);
	}

	return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		ll x;
		cin >> x;
		update(i, x);
	}

	m += k;
	while (m--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(c) - query(b - 1) << "\n";
	}

}