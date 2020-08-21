#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> arr[200000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s, t;
		cin >> s >> t;
		arr[i] = { s, t };
	}
	priority_queue<int> pq;
	sort(arr, arr + n);
	int ans = 1;
	pq.push(-arr[0].second);
	for (int i = 1; i < n; i++)
	{
		int lo = -pq.top();
		if (lo <= arr[i].first) pq.pop();

		pq.push(-arr[i].second);
	}

	cout << pq.size();
}