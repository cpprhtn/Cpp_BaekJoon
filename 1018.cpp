#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

const int INF = 987654321;

const int MAX = 50;

int M, N;

string board[MAX];

string warr[8] = {
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }
};

string barr[8] = {
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }
};

int warrChange(int y, int x)
{
	int cnt = 0;

	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != warr[i - y][j - x])
				cnt++;



	return cnt;

}

int barrChange(int y, int x)
{
	int cnt = 0;

	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != barr[i - y][j - x])
				cnt++;

	return cnt;
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	int result = INF;

	for (int i = 0; i + 7 < N; i++)
		for (int j = 0; j + 7 < M; j++)
			result = min(result, min(warrChange(i, j), barrChange(i, j)));

	cout << result << endl;

	return 0;
}