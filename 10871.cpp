#include <iostream>

using namespace std;

int main()
{
    int n, x, temp;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> temp;
        if (temp < x){
            cout << temp << " ";
        }
    }
}