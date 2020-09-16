#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
struct state { string s; int z; };
int d[] = { -1, 1, -3, 3 };

int main()
{
	string s, g = "123456780";
	int sz, cnt = 0;
	for (int i = 0; i < 9; i++)
	{
		s += cin.get();
		if (s.back() == '0')
			sz = i;

		cin.get();
	}

	queue<state> Q;
	unordered_set<string> v;
	Q.push({ s, sz });
	v.insert(s);
	while (Q.size())
	{
		int size = Q.size();
		while (size--)
		{
			string cur = Q.front().s;
			int z = Q.front().z;
			Q.pop();

			if (cur == g)
			{
				cout << cnt;
				return 0;
			}

			for (int i = 0; i < 4; i++)
			{
				int nz = z + d[i];
				if (nz >= 0 && nz < 9 && (nz % 3 == z % 3 || nz / 3 == z / 3))
				{
					swap(cur[nz], cur[z]);
					if (v.find(cur) == v.end())
					{
						Q.push({ cur, nz });
						v.insert(cur);
					}
					swap(cur[nz], cur[z]);
				}
			}
		}
		cnt++;
	}

	cout << -1;
}