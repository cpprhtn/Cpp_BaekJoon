#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll arr[200001];
unordered_map<long long, int> M;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k, ans = 0;
	cin >> n >> k;
	M[0]++;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
		M[arr[i]]++;
	}

	for (int i = n; i; i--)
	{
		M[arr[i]]--;
		ans += M[arr[i] - k];
	}

	cout << ans;
}
