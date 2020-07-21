#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000];
int main()
{
	int n, l;
	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int cur = arr[0], cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] - cur + 1 > l)
			cnt++, cur = arr[i];
	}

	printf("%d", cnt);
}