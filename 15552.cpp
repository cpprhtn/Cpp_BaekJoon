#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}
}