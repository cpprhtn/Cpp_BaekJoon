#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    int num;
    cin >> num;
    vector<pair<long,long>> arr;
    pair<long,long> vec;
    for(int i = 0; i < num; i++)
    {
        cin >> vec.first >> vec.second;
        arr.push_back(vec);
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < num; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
}