//(1)dp이용
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct pos {
	int x;
	int y;
	int c;
	pos(int _x, int _y, int _c) : x(_x), y(_y), c(_c) {};
}pos;

char map[50][50];
int N, dp[50][50];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
queue<pos> Q;

int main()
{
	int i, j;
	int tx, ty, tc, nx, ny;

	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
			dp[i][j] = 9999;
		}
	}

	if (map[0][0] == '1') {
		dp[0][0] = 0;
		Q.push(pos(0, 0, 0));
	}
	else {
		dp[0][0] = 1;
		Q.push(pos(0, 0, 1));
	}

	while (!Q.empty()) {
		tx = Q.front().x;
		ty = Q.front().y;
		tc = Q.front().c;
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = tx + dir[i][0];
			ny = ty + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (map[nx][ny] == '1' && tc < dp[nx][ny]) {
					dp[nx][ny] = tc;
					Q.push(pos(nx, ny, tc));
				}
				else if (map[nx][ny] == '0' && tc + 1 < dp[nx][ny]) {
					dp[nx][ny] = tc + 1;
					Q.push(pos(nx, ny, tc + 1));
				}
			}
		}
	}

	cout << dp[N - 1][N - 1] << endl;
	return 0;
}

//(2)heap으로 구현
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef struct pos {
	int x;
	int y;
	int c;
	pos(int _x, int _y, int _c) : x(_x), y(_y), c(_c) {};
}pos;

struct compare {
	bool operator()(const pos& a, const pos& b) {
		return a.c > b.c;
	}
};
char map[50][50];
bool visit[50][50];
int N, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
priority_queue<pos, vector<pos>, compare> Q;

int main()
{
	int i, j;
	int tx, ty, tc, nx, ny;

	cin >> N;
	memset(visit, false, sizeof(bool) * N);
	for (i = 0; i < N; i++) {
		memset(visit[i], false, sizeof(bool) * N);
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	visit[0][0] = true;
	if (map[0][0] == '1') {
		Q.push(pos(0, 0, 0));
	}
	else {
		Q.push(pos(0, 0, 1));
	}

	while (!Q.empty()) {
		tx = Q.top().x;
		ty = Q.top().y;
		tc = Q.top().c;
		if (tx == N - 1 && ty == N - 1)
			break;
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = tx + dir[i][0];
			ny = ty + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
				visit[nx][ny] = true;
				if (map[nx][ny] == '0')
					Q.push(pos(nx, ny, tc + 1));
				else
					Q.push(pos(nx, ny, tc));
			}
		}
	}

	cout << tc << endl;
	return 0;
}
