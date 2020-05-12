#include<iostream>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	int ans1 = (a + b) % c, ans2 = (a%c + b%c) % c, ans3 = (a*b) % c, ans4 = (a%c*b%c) % c;
	cout << ans1 << endl << ans2 << endl << ans3 << endl << ans4 << endl;
}