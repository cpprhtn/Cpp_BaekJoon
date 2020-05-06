#include <cstdio>

int main()
{
	long double a, b;
	scanf("%Lf %Lf", &a, &b);

	printf("%.10Lf", a / b);
}