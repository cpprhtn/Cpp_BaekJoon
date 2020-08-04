#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll arr[21], request[21];
void solve(ll l, ll w, ll h, ll s)
{
	if (!l || !w || !h || s == -1) return;
	ll a, b, c, d, e, f, x;
	x = 1 << s;
	a = l / x;
	b = w / x;
	c = h / x;
	d = l % x;
	e = w % x;
	f = h % x;

	request[s] += a * b * c;
	solve(d, x*b, x*c, s - 1);
	solve(x*a, e, x*c, s - 1);
	solve(x*a, x*b, f, s - 1);
	solve(d, e, x*c, s - 1);
	solve(d, x*b, f, s - 1);
	solve(x*a, e, f, s - 1);
	solve(d, e, f, s - 1);
}
int main()
{
	ll l, w, h, n, cnt = 0;
	cin >> l >> w >> h >> n;

	ll max_s = 0;
	for (ll i = 0; i < n; i++)
	{
		ll s, k;
		cin >> s >> k;
		arr[s] += k;
		cnt += k;
		max_s = max(max_s, s);
	}

	solve(l, w, h, max_s);
	ll ans = 0;
	for (ll i = max_s; i; i--)
	{
		if (request[i] < arr[i])
		{
			ans += request[i];
		}
		else
		{
			ans += arr[i];
			request[i - 1] += (request[i] - arr[i]) * 8;
		}
	}

	ans += min(arr[0], request[0]);
	cout << (arr[0] >= request[0] ? ans : -1);
}