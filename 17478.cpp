#include <bits/stdc++.h>
using namespace std;
int N;
void _bar(const char* str, int stk) {
    for (int j = 0; j < stk; ++j) cout << "____";
    cout << str;
}
void solve(int cnt) {
    _bar("\"����Լ��� ������?\"\n", cnt);
    if (cnt == N) _bar("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", cnt);
    else {
        _bar("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", cnt);
        _bar("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", cnt);
        _bar("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", cnt);
        solve(cnt + 1);
    }
    _bar("��� �亯�Ͽ���.\n", cnt);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    solve(0);
}