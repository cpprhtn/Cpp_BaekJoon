#include <cstdio>
#include <cmath>
#include <algorithm>
long long tree[400001];

int n, q, x, y;
int start;
long long getSum(int l, int r, int c)
{
	int mid = (l + r) / 2;
	if (y<l || x>r)
		return 0;

	if (l >= x && r <= y)
	{
		return tree[c];
	}

	return getSum(mid + 1, r, c * 2 + 1) + getSum(l, mid, c * 2);
	
}

void update(int a, long long b)
{
	a += start - 1;
	long long cur = tree[a];
	while (a)
	{
		tree[a] += -cur + b;
		a /= 2;
	}

}

int main()
{
	scanf("%d %d", &n, &q);
	start = 1 << (int)ceil(log2(n));

	for (int i = start; i < start + n; i++)
	{
		scanf("%lld", &tree[i]);
		int tmp = i / 2;
		while (tmp)
		{
			tree[tmp] += tree[i];
			tmp /= 2;
		}
	}

	while (q--)
	{
		int a;
		long long b;
		scanf("%d %d %d %lld", &x, &y, &a, &b);
		if (x > y)
			std::swap(x, y);
		printf("%lld\n", getSum(1, start, 1));
		update(a, b);
	}
}