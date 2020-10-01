#include <cstdio>
#include <queue>
using namespace std;

struct xy
{
	int x, y, l;
};
int hx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int hy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int mx[] = { 0, 0, 1, -1 };
int my[] = { 1, -1, 0, 0 };
int k, w, h;
int arr[200][200];
int visit[200][200] = {};
int main()
{
	queue<xy> Q;
	int count = 0;
	scanf("%d %d %d", &k, &h, &w);
	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			scanf("%d", &arr[i][j]), visit[i][j]=-1;

	Q.push({ 0, 0, k });
	Q.push({ -1, -1, 0});
	visit[0][0] = k;
	while (Q.size())
	{
		xy cur = Q.front();
		Q.pop();
		if (cur.x == -1)
		{
			if (Q.empty())
			{
				printf("-1");
				return 0;
			}

			count++, Q.push({ -1, -1, 0 });
			continue;
		}

		if (cur.x == w - 1 && cur.y == h - 1)
		{
			printf("%d", count);
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + mx[i], ny = cur.y + my[i];
			if (nx >= 0 && nx < w && ny >= 0 && ny < h && !arr[nx][ny] && visit[nx][ny]<cur.l)
				visit[nx][ny] = cur.l, Q.push({ nx, ny, cur.l });
		}

		if (cur.l)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = cur.x + hx[i], ny = cur.y + hy[i];
				if (nx >= 0 && nx < w && ny >= 0 && ny < h && !arr[nx][ny] && visit[nx][ny] < cur.l - 1)
					visit[nx][ny] = cur.l - 1, Q.push({ nx, ny , cur.l - 1 });
			}
		}

	}
}
