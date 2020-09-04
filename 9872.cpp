#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	map<vector<string>, int> M;
	int ans = 0;
	cin >> n;
	while(n--)
	{
		vector<string>str(3);
		for (int i = 0; i < 3; i++)
			cin >> str[i];

		sort(str.begin(), str.end());
		int &x = M[str];
		ans=max(ans, ++x);
	}
	cout << ans;
}