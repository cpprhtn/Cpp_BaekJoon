#include <cstdio>
#include <vector>
using namespace std;


int main(void)
{
	vector<int> arr;
	int n, m, pos;
	scanf("%d %d", &n, &m);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		arr[i]=i+1;

	pos = m-1;
	printf("<%d", m);
	while (n--)
	{
		if (!n)
			break;

		arr.erase(arr.begin() + pos);
		pos += m - 1;

		pos %= n;
		printf(", %d", arr[pos]);
	}
	printf(">\n");

	return 0;
}
