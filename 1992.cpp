#include <bits/stdc++.h>
using namespace std;

int N;
const int MAX = 64;
int arr[MAX][MAX];
void solve(int n, int y, int x)
{
    if (n == 1) {
        cout << arr[y][x];
        return;
    }
    bool zero = true, one = true;
    for (int i = y; i < y + n; i++)
        for (int j = x; j < x + n; j++)
            if (arr[i][j])
                zero = false;
            else
                one = false;
    if (zero)
        cout << 0;
    else if (one)
        cout << 1;
    else {
        cout << "(";
        solve(n / 2, y, x); //���� ��
        solve(n / 2, y, x + n / 2); //������ ��
        solve(n / 2, y + n / 2, x); //���� �Ʒ�
        solve(n / 2, y + n / 2, x + n / 2); //������ �Ʒ�
        cout << ")";
    }
    return;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
            arr[i][j] = str[j] - '0';
    }
    solve(N, 0, 0);
}