#include <cstdio>
using namespace std;
const int move_x[4]={1, -1, 0, 0};
const int move_y[4]={ 0, 0, 1, -1};

bool map[51][52]={}, visit[52][52]={};
int count;
int dfs(int x, int y)
{
	for(int i=0; i<4; i++)
	{
		int nx=x+move_x[i], ny=y+move_y[i];
		if(map[nx][ny] && !visit[nx][ny])
			visit[nx][ny]=true, dfs(nx, ny);
	}
}
int main()
{
	int t, row, col, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &row, &col, &n);
		for(int i=1; i<=row; i++)
			for(int j=1; j<=col; j++)
				map[i][j]=visit[i][j]=false;

		while(n--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			map[x+1][y+1]=true;
		}

		for(int i=1; i<=row; i++)
			for(int j=1; j<=col; j++)
			{
				if(map[i][j] && !visit[i][j])
					visit[i][j]=true, count++, dfs(i, j);
			}

		printf("%d\n", count);
		count=0;
	}
	return 0;
}
