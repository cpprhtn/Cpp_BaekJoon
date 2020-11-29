#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> arr;

    int num,tmp,range,middle = 0,most_f,mean = 0;
    int most = -10000;
    int number[8001] = {0,};
    bool not_first = false;
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        mean += tmp;
        number[tmp+4000]++;
    }

    sort(arr.begin(),arr.end());

    for(int i = 0; i < 8001; i++)
    {
        if(number[i] == 0)
            continue;
        if(number[i] == most)
        {
            if(not_first)
            {
                most_f = i - 4000;
                not_first = false;
            }
        }
        if(number[i] > most)
        {
            most = number[i];
            most_f = i - 4000;
            not_first = true;
        }
    }

    mean = round(static_cast<double>(mean) / num);
    middle = arr[arr.size()/2];
    range = arr.back() - arr.front();
    cout << mean << '\n' << middle << '\n' << most_f << '\n' << range;
}