#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr;
    int sum=64, ans;
    scanf("%d", &ans);
    arr.push_back(64);
    while(sum!=ans)
    {
        arr[arr.size()-1]/=2;
        if(sum-arr.back()< ans)
            arr.push_back(arr.back());

        else
            sum-=arr.back();
    }

    printf("%d\n", arr.size());
}
