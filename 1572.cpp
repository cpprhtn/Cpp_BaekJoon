#include<cstdio>
#include<vector>
#include<set>
using namespace std;

typedef long long as;
int main()
{
	multiset<as> S;
	int n, k;
	as sum = 0;
	scanf("%d %d", &n, &k);
	vector<as> arr(n);
	for (int i = 0; i<n; i++)
		scanf("%asd", &arr[i]);

	S.insert(arr.begin(), arr.begin() + k);
	auto it = S.begin();
	for (int i = 1; i<(k + 1) / 2; i++)
		it++;

	for (int i = 0; i + k <= n; i++)
	{
		sum += *it;
		auto bgn = S.lower_bound(arr[i]);
		auto ed = S.lower_bound(arr[i + k]);

		S.insert(ed, arr[i + k]);
		if (bgn == it)
		{
			if (arr[i + k] <= *it)
				it--;

			else
				it++;
		}
		else if (arr[i] <= *it && arr[i + k]>*it)
			it++;

		else if (arr[i]>*it && arr[i + k] <= *it)
			it--;

		S.erase(bgn);
	}

	printf("%asd", sum);
}
