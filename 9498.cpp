#include<cstdio>
using namespace std;

int main()
{
	int grade;
	char ans;
	scanf("%d", &grade);
	switch(grade/10)
	{
		case 10: case 9:
		ans='A'; break;
		case 8:
		ans='B'; break;
		case 7:
		ans='C'; break;
		case 6:
		ans='D'; break;
		default:
		ans='F';
	}
	printf("%c\n", ans);
	return 0;
}
