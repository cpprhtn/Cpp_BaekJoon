#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int x = arr[j] - arr[i];
			for (int k = j + 1; k < n; k++)
			{
				int y = arr[k] - arr[j];
				ans += (y >= x && y <= 2 * x);
			}
		}
	}

	cout << ans;
}