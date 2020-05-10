#include <cstdio>
#include <vector>
using namespace std;

vector<int> tree[50];

int dfs(int x)
{
	if (tree[x].empty())
		return 1;

	int count=0;
	for (auto i : tree[x])
		count += dfs(i);

	return count;
}
int main()
{
	int n, root, ans, delete_node;
	int parent[50] = {};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int p;
		scanf("%d", &p);
		if (p == -1)
			root = i, parent[i]=-1;

		else
			tree[p].push_back(i), parent[i]=p;
	}

	scanf("%d", &delete_node);
	tree[delete_node].clear();
	ans=dfs(root);
	if (parent[delete_node] == -1 || tree[parent[delete_node]].size() != 1)
		ans--;
	printf("%d", ans);
}