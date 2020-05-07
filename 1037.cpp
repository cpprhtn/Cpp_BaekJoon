#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int no_divisor;
	vector<int> divisor;

	scanf("%d", &no_divisor);
	divisor.resize(no_divisor);
	for(int i=0; i<no_divisor; i++)
		scanf("%d", &divisor[i]);

	sort(divisor.begin(), divisor.end());
	printf("%d\n", divisor.front()*divisor.back());
	return 0;
}
