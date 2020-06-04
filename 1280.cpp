#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 200000
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct cc
{
	ll cost, cnt;
	cc operator +(cc x)
	{
		cost += x.cost;
		cnt += x.cnt;
		return *this;
	}
};

ll arr[MAX + 1], sorted[MAX + 1], ans = 1;
cc st[4 * MAX];
int n, s;

void update(int p, ll x)
{
	cc px = { x, 1 };
	p += s;
	while (p)
	{
		st[p] = st[p] + px;
		p >>= 1;
	}
}

cc query(int l, int r, int p, int x, int y)
{
	if (l > y || r < x) return { 0, 0 };
	if (l <= x && r >= y) return st[p];
	int mid = (x + y) >> 1;
	return query(l, r, p << 1, x, mid) + query(l, r, (p << 1) + 1, mid + 1, y);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	s = 1 << int(ceil(log2(n)));

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sorted[i] = arr[i];
	}

	sort(sorted, sorted + n);
	int it = lower_bound(sorted, sorted + n, arr[0]) - sorted;
	update(it, arr[0]);

	for (int i = 1; i < n; i++)
	{
		it = lower_bound(sorted, sorted + n, arr[i]) - sorted;
		cc a = query(0, it, 1, 0, s - 1);
		cc b = query(it, n - 1, 1, 0, s - 1);
		ans = (ans * (((arr[i] * a.cnt - a.cost) + (b.cost - arr[i] * b.cnt)) % MOD)) % MOD;
		update(it, arr[i]);
		if (ans == 0) break;
	}

	cout << ans;
}