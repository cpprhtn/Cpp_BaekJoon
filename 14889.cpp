#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_SIZE 21

int n;
bool is_used[MAX_SIZE];
int s[MAX_SIZE][MAX_SIZE];
int ans = 987654321;

// curr_player번 선수를 스타트 팀으로 뽑는다, cnt : 뽑은 명수
void Dfs(int curr_player, int cnt)
{
    // n/2명을 뽑았으면 차이를 계산
    if (cnt == n / 2)
    {
        vector<int> team_link, team_start;

        // 뽑은 선수들은 스타트팀으로
        for (int i = 0; i < n; i++)
        {
            if (is_used[i]) team_start.push_back(i);
            else team_link.push_back(i);
        }

        // 스타트팀과 링크팀의 능력치 차이 구하기
        int stat_start = 0, stat_link = 0;
        for (int i = 0; i < team_start.size(); i++)
        {
            for (int j = i+1; j < team_start.size(); j++)
            {
                int start_x = team_start[i], start_y = team_start[j];
                int link_x = team_link[i], link_y = team_link[j];
                stat_start += s[start_x][start_y] + s[start_y][start_x];
                stat_link += s[link_x][link_y] + s[link_y][link_x];
            }
        }

        ans = min(ans, abs(stat_start - stat_link));
        return;
    }

    // 완전탐색
    for (int i = curr_player+1; i < n; i++)
    {
        if (is_used[i] == false)
        {
            is_used[i] = true;
            Dfs(i, cnt + 1);
            // 백트래킹
            is_used[i] = false;
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    Dfs(0,0);

    cout << ans << "\n";

    return 0;
}