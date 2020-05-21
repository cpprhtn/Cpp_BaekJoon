#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string &a, string &b)
{
	if (a.size() != b.size())
		return (a.size() < b.size());

	return a.compare(b)<0;
}

int main()
{
	vector<string> str;
	int no_word;
	cin >> no_word;
	for (int i = 0; i < no_word; i++)
	{
		string temp;
		cin >> temp;
		str.push_back(temp);
	}

	sort(str.begin(), str.end(), cmp);
	cout << str.front()<<"\n";

	for (int i = 1; i < no_word; i++)
		if (str.at(i - 1) != str.at(i))
			cout << str.at(i) << "\n";

	return 0;
}
