#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    char tmp;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d,", &arr[i]);

    while(k--)
    {
        for(int j=0; j<arr.size()-1; j++)
            arr[j]=arr[j+1]-arr[j];

        arr.erase(arr.end()-1);
    }
    printf("%d", arr[0]);
    for(int i=1; i<arr.size(); i++)
        printf(",%d", arr[i]);
}