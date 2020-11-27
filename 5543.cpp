#include <cstdio>
using namespace std;

int main()
{
	int b[3], d[2];
	int min=10000;
	scanf("%d %d %d %d %d", &b[0], &b[1], &b[2], &d[0], &d[1]);
	for(int i=0; i<3; i++)
		for(int j=0; j<2; j++)
			if(min>b[i]+d[j])
				min=b[i]+d[j];

	printf("%d\n", min-50);
}
