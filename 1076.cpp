#include<iostream>
#include<string>
#include<map>
#include<cmath>
using namespace std;

int main()
{
	map<string, long long> ohm;
	ohm["black"] = 0, ohm["brown"] = 1, ohm["red"] = 2, ohm["orange"] = 3, ohm["yellow"] = 4,
	ohm["green"] = 5, ohm["blue"] = 6, ohm["violet"] = 7, ohm["grey"] = 8, ohm["white"] = 9;

	string a, b, c;
	long long ans;
	cin >> a >> b >> c;

	ans = (ohm[a] * 10 + ohm[b])*(long long)pow(10, ohm[c]);
	cout << ans << endl;
	return 0;
}