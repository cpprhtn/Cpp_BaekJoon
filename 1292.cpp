#include <cstdio>
#include <vector>
using namespace std;

vector<long long> dp;
int main()
{
	int sum[1201]={};
	int s, e, v=0;
	scanf("%d %d", &s, &e);
	for(int i=1; i<=e; i++)
	{
		v++;
		for(int j=0; j<v; j++)
			sum[i+j]=sum[i+j-1]+v;

		i+=v-1;
	}

	printf("%d\n", sum[e]-sum[s-1]);
}
