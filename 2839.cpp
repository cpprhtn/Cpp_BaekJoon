#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n, f, t=-1;
	scanf("%d", &n);
	f=n/5;
	for(int i=0; i<3 && (f-i)>=0; i++)
	{
		if((n-(f-i)*5)%3==0)
		{
			t=(n-(f-i)*5)/3, f-=i;
			break;
		}
	}
	if(t==-1)
		printf("-1\n");

	else
		printf("%d\n", f+t);
	return 0;
}
