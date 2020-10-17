#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, c;
	int num[10] = { 0, };
	scanf("%d %d %d", &a, &b, &c);

	string ans = to_string(a * b * c);
	
	for (int i = 0; i < ans.size(); i++)
		num[ans[i] - '0']++;

	for (int i = 0; i < 10; i++)
		printf("%d\n", num[i]);

	return 0;

}
