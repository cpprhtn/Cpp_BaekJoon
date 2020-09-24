#include <cstdio>

int main()
{
	int num, max=-1;

	scanf("%d", &num);
	double *grade = new double[num], sum=0, ans;

	for (int i = 0; i < num; i++)
	{
		scanf("%lf", grade+i);
		if (grade[i] > max)
			max = grade[i];

		sum += grade[i];
	}

	ans = sum / max / num * 100;

	printf("%.2lf", ans);
	return 0;
}