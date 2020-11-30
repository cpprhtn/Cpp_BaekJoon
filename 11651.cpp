#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool func(pair<long,long> a, pair<long,long> b)
{

    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main() {
    int num;
    cin >> num;
    vector<pair<long,long>> arr;
    pair<long,long> tmp;
    for(int i = 0; i < num; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end(),func);
    for(int i = 0; i < num; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
}