#include <cstdio>

int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int main()
{
	int board[6][6] = {};
	char rc[3];
	int count = 1;

	scanf("%s", rc);
	rc[0] -= 'A';
	rc[1] -= '1';
	board[rc[0]][rc[1]] = 1;
	int sr = rc[0], sc = rc[1];
	bool isRight = true;
	do
	{
		int pr = rc[0], pc = rc[1];
		scanf("%s", rc);
		rc[0] -= 'A';
		rc[1] -= '1';
		if (board[rc[0]][rc[1]])
		{
			isRight = false;
			break;
		}
		board[rc[0]][rc[1]] = 1;
		for (int i = 0; i < 8; i++)
		{
			int nx = rc[0] + dx[i], ny = rc[1] + dy[i];
			if (nx == pr && ny == pc)
			{
				board[rc[0]][rc[1]] = true;
				break;
			}

			if (i == 7)
				isRight=false;
		}

	} while (++count != 36);

	if (!isRight)
		printf("Invalid");

	else
	{
		for (int i = 0; i < 8; i++)
		{
			int nx = rc[0] + dx[i], ny = rc[1] + dy[i];
			if (nx == sr && ny == sc)
			{
				printf("Valid");
				return 0;
			}
		}

		printf("Invalid");
	}
}