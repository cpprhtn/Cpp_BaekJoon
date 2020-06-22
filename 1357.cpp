#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string num1, num2, ans;
	int sum;
	cin >> num1 >> num2;

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	sum = stoi(num1) + stoi(num2);

	ans = to_string(sum);
	reverse(ans.begin(), ans.end());
	cout << stoi(ans) << endl;
}
