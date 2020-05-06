#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Planet {
	int x, y;
	int rad;
	Planet() {}
	Planet(int x, int y, int r) :x(x), y(y), rad(r) {}
	bool operator == (Planet o) {
		return (x == o.x && y == o.y && rad == o.rad);
	}
	bool operator < (Planet o) {
		return rad < o.rad;
	}
}p[50];

int dist(Planet &a, Planet &b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
int t;
vector<Planet> s, e;
int sx, sy, ex, ey, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		sx = sy = ex = ey = n = 0;
		memset(p, 0, sizeof(p));
		s.clear();
		e.clear();

		cin >> sx >> sy >> ex >> ey >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y >> p[i].rad;
			if (dist(sx, sy, p[i].x, p[i].y) < p[i].rad*p[i].rad) {
				s.push_back(p[i]);
			}
			if (dist(ex, ey, p[i].x, p[i].y) < p[i].rad*p[i].rad) {
				e.push_back(p[i]);
			}
		}
		sort(s.begin(), s.end());
		sort(e.begin(), e.end());



		int a = 0, b = 0;
		int ans = 0;
		while (a < s.size() && b < e.size()) {
			if (s[a] == e[b]) {
				break;
			}
			else {
				ans++;
				if (s[a].rad <= e[b].rad)
					a++;
				else if (s[a].rad > e[b].rad)
					b++;
			}
		}
		if (a == s.size()) ans += e.size() - b;
		if (b == e.size()) ans += s.size() - a;
		cout << ans << '\n';
	}
}
