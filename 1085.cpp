#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int xd = min(x - 0, w - x), yd = min(y - 0, h - y);
	printf("%d\n", min(xd, yd));
	return 0;
}
