#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<long,long>> arr;
    pair<long,long> vec;
    int k = 0;
    cin >> k;
    for (int i = 0; i<k; i++)
    {
        cin >> vec.first >> vec.second;
        arr.push_back(vec);
    }
    
    sort(arr.begin(), arr.end());

    for (int i = 0; i<k; i++)
    {
        cout << arr[i].first << " " << arr[i].second << endl;
    }
}