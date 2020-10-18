#include <cstdio>
#include <set>
using namespace std;
int main()
{
	set<int> a;
	for (int i = 0; i < 10; i++)
	{
		int num;
		scanf("%d", &num);
		a.insert(num%42);
	}

	printf("%d\n", a.size());
	return 0;
}	