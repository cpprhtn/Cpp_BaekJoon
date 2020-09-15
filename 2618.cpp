#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int row, col;
int num;
int cache[1000][1000];

vector<pair<int, int>> pathA;
vector<pair<int, int>> pathB;
vector<int> v;


int Max_distance(int A, int B)
{	
    if (A == num || B == num)
        return 0;

    int& ret = cache[A][B];

    if (ret != -1)
        return ret;

    ret = 987654321;
    
    int maxLocation = max(A, B) + 1;

    int distA = abs(pathA[maxLocation].first - pathA[A].first) +
        abs(pathA[maxLocation].second - pathA[A].second);

    int distB = abs(pathB[maxLocation].first - pathB[B].first) +
        abs(pathB[maxLocation].second - pathB[B].second);

    int ret1 = Max_distance(maxLocation, B) + distA;
    int ret2 = Max_distance(A, maxLocation) + distB;

    return ret = min(ret1, ret2);
}

void reconstruct(int A, int B)
{
    if (A == num || B == num)
        return;

    int maxLocation = max(A, B) + 1;

    int distA = abs(pathA[maxLocation].first - pathA[A].first) +
        abs(pathA[maxLocation].second - pathA[A].second);

    int distB = abs(pathB[maxLocation].first - pathB[B].first) +
        abs(pathB[maxLocation].second - pathB[B].second);

    int ret1 = Max_distance(maxLocation, B) + distA;
    int ret2 = Max_distance(A, maxLocation) + distB;

    if (ret1 > ret2)
    {
        cout << 2 << endl;
        reconstruct(A, maxLocation);
    }
    else
    {
        cout << 1 << endl;
        reconstruct(maxLocation, B);
    }

}

void solve()
{
    cout << Max_distance(0, 0) << endl;
    reconstruct(0, 0);
}

int main()
{
    cin >> row;	col = row;
    cin >> num;
    
    memset(cache, -1, sizeof(cache));

    pathA.push_back({ 1, 1 });
    pathB.push_back({ row, row });
    
    for (int i = 0; i < num; i++)
    {
        int x, y;	cin >> x >> y;
        pathA.push_back({ x, y });
        pathB.push_back({ x, y });
    }
    
    solve();

    return 0;
}