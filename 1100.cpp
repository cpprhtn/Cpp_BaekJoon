#include<cstdio>
using namespace std;

int main()
{
	char a[9];
	int ans=0;
	for(int i=0; i<8; i++)
	{
		scanf("%s", a);
		for(int j=0; j<8; j++)
		{
			if(a[j]=='F' && (i%2==0 && j%2==0 || i%2==1 && j%2==1))
				ans++;

		}
	}

	printf("%d\n", ans);
}
