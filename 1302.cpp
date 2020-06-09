#include<iostream>
#include<string>
#include<map>

using namespace std;
int main()
{
	int n, max=0;
	map<string, int> M;
	string ans = "";
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		M[str]++;
	}

	for (auto i : M)
	{
		if (max < i.second)
			ans = i.first, max = i.second;
	}

	cout << ans;
}