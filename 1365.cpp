#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> arr;
	int n, num;
	cin >> n >> num;
	arr.push_back(num);
	for (int i = 1; i < n; i++)
	{
		cin >> num;
		if (num > arr.back())
		{
			arr.push_back(num);
		}

		else
		{
			auto it = lower_bound(arr.begin(), arr.end(), num);
			*it = num;
		}
	}

	cout << n - arr.size();
}