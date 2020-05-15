#include <cstdio>
#include <string>
#define abs(x) ((x)>0? (x): (x)*(-1))
using namespace std;
int main()
{
	int n, m, upper, lower, count = 0, normal;
	bool find = true;
	string tostr, ans;
	int brk[10];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
		scanf("%d", &brk[i]);

	upper = lower = n;
	normal = abs(n - 100);
	while (find && count<normal)
	{
		find = false;
		tostr = to_string(lower);
		for (int i = 0; i<m; i++)
		{
			if (tostr.find(brk[i] + '0') != string::npos)
			{
				find = true;
				if(lower>0)
					lower--;
				break;
			}
		}

		if (!find)
		{
			ans = tostr;
			break;
		}

		find = false;
		tostr = to_string(upper);
		for (int i = 0; i<m; i++)
		{
			if (tostr.find(brk[i] + '0') != string::npos)
			{
				find = true;
				upper++;
				break;
			}
		}

		if (!find)
		{
			ans = tostr;
			break;
		}

		count++;
	}

	if (count + ans.size() > normal)
		count = normal;

	else
		count += ans.size();

	printf("%d", count);
}