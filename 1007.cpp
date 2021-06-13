#include<stdio.h>
#include<math.h>


int com[20];
double const max = 9223372036854775807;
double temp, ans;
int x[20], y[20];
int sum_x, sum_y;
int T, N, V;

void combination(int N, int R, int q)
{
	if (R == 0)
	{
		int temp_x = sum_x;
		int temp_y = sum_y;
		for (int i = 0; i < q; i++)
		{
			temp_x -= 2 * x[com[i]];
			temp_y -= 2 * y[com[i]];
		}

		temp = sqrt(pow(temp_x, 2) + pow(temp_y, 2));

		if (temp < ans) 
			ans = temp;

	}
	else if (N < R) return;

	else
	{
		com[R - 1] = N - 1;
		combination(N - 1, R - 1, q);
		combination(N - 1, R, q);
	}
}

int main(void)
{

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		sum_x = 0;
		sum_y = 0;
		ans = max;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d %d", &x[j], &y[j]);
			sum_x += x[j];
			sum_y += y[j];
		}

		combination(N, N / 2, N / 2); 
		printf("%.12f\n", ans);
	}

}