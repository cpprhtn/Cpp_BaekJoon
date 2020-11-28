#include <iostream>
using namespace std;

int main() 
{
    int num;
    int arr[1000] = {0,};
    int tmp;
    cin >> num;
    for(int i = 0; i < num; i++)
        cin >> arr[i];
    for(int i = num; i > 1; i--)
        for(int j = 0; j+1 < i; j++)
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
    for(int i = 0; i < num; i++)
        cout << arr[i] << '\n';
}