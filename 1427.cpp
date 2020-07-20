#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string number;
	cin >> number;

	sort(number.rbegin(), number.rend());

	cout << number << endl;
}
