#include <cstdio>
using namespace std;

int main()
{
	int y;
	scanf("%d", &y);
	printf("%d\n", ((y%100!=0 && y%4==0) || y%400==0));
	return 0;
}
