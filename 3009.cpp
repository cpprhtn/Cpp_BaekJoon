#include<cstdio>
#include<map>
using namespace std;

int main()
{
	map<int, int>dx, dy;
	int a, b;
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		dx[x]++, dy[y]++;
	}
	for (auto i : dx)
		if (i.second == 1)
			a = i.first;

	for (auto i : dy)
		if (i.second == 1)
			b = i.first;

	printf("%d %d", a, b);
}