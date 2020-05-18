#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	int ans = 55;
	cin >> a >> b;
	for (int i = 0; i + a.size() <= b.size(); i++)
	{
		int temp = 0;
		for (int j = 0; j < a.size(); j++)
			if (b[i + j] != a[j])
				temp++;

		if (ans > temp)
			ans = temp;
	}

	printf("%d", ans);
}