#include <stdio.h>

int T;				// 테스트 케이스의 개수
int M, N;			// 배추밭의 가로 세로 길이
int K;				// 배추 개수
int worm_count;		// 지렁이 개수
int arr[50][50];
int cnt_arr[50][50];// 계산했는지 카운트하기 위한 배열

// 상하좌우
int dRow[4] = { 1, -1, 0, 0 };
int dCol[4] = { 0, 0, 1, -1 };


// 이어진 배추를 찾는 DFS 함수
void Connected(int row, int col) {
	cnt_arr[row][col] = 1; // 체크

	// 상하좌우 확인
	for (int i = 0; i < 4; i++) {
		int nRow = row + dRow[i];
		int nCol = col + dCol[i];

		if (nRow < 0 || nRow >= N || nCol < 0 || nCol >= M) // 해당 땅이 배추밭 범위를 벗어났다면 넘어간다.
			continue;

		// 해당 땅이 배추가 있고 아직 계산에 포함되지 않았다면
		if (arr[nRow][nCol] == 1 && cnt_arr[nRow][nCol] == 0)
			Connected(nRow, nCol); // DFS 함수 호출
	}
}

int main() {

	scanf("%d\n", &T);


	for (int i = 0; i < T; i++) {
		scanf("%d %d %d\n", &M, &N, &K);

		for (int j = 0; j < N; j++) {
			for (int p = 0; p < M; p++) {
				arr[j][p] = 0;
				cnt_arr[j][p] = 0;
			}
		}

		int A, B;
		for (int j = 0; j < K; j++) {
			scanf("%d %d\n", &B, &A);
			arr[A][B] = 1; // 입력받은 위치의 값을 1로 바꿈 (즉 배추가 존재함)
		}

		worm_count = 0; // 지렁이 개수 초기화
		for (int j = 0; j < N; j++) {
			for (int p = 0; p < M; p++) {
				if (arr[j][p] == 1 && cnt_arr[j][p] == 0) { // 배추가 있는 땅이면서 아직 확인하지 않은 땅일때
					worm_count++; // 지렁이의 카운트 증가
					Connected(j, p); // 해당 배추와 이어진 배추들은 찾아봄
				}
			}
		}
		printf("%d\n", worm_count);
	}
	return 0;
}