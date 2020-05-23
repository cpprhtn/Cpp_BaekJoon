#include <cstdio>
#include <queue>
#define n2(x) (1 << x)
using namespace std;

struct xy
{
	int c, x, y;
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	int n, m, count = 1;
	char map[51][51];
	int  visit[64][50][50] = {};
	queue<xy> Q;
	scanf("%d %d", &n, &m);

	for (int i = 0; i<n; i++)
	{
		scanf("%s", map[i]);
		for (int j = 0; j<m; j++)
		{
			if (map[i][j] == '0')
				Q.push({ 0, i, j }), visit[0][i][j] = 1;
		}
	}

	Q.push({ -1, -1, -1 });
	while (1)
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

			Q.push({-1, -1, -1 }), count++;
			continue;
		}		

		for (int i = 0; i<4; i++)
		{
			int key = cur.c, nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (nx >= 0 && nx<n && ny >= 0 && ny<m && map[nx][ny] != '#')
			{
				if (map[nx][ny] == '1')
				{
					printf("%d", count);
					return 0;
				}

				char &pos = map[nx][ny];
				if ((pos == '.' || pos == '0') && !visit[key][nx][ny]);

				else if (pos >= 'a' && pos <= 'f' && !visit[key + (key & n2(pos - 'a') == 0 ? n2(pos - 'a'):0)][nx][ny])
				{
					if((key & n2(pos - 'a')) == 0)
						key += n2(pos - 'a');
				}

				else if (pos >= 'A' && pos <= 'F' && (key & n2(pos - 'A')) != 0 && !visit[key][nx][ny]);

				else continue;

				visit[key][nx][ny] = 1;
				Q.push({ key, nx, ny });
			}
		}
	}
}