#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct pos {
	int x;
	int y;
	int s;
	int d;
	pos(int _x, int _y, int _s, int _d) : x(_x), y(_y), s(_s), d(_d){};
}pos;
int map[1000][1000], dp[2][1000][1000];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
queue<pos> Q;

int main()
{
	int i, j, N, M, x, y;
	int tx, ty, ts, td, nx, ny;

	cin >> N >> M;
	cin >> x >> y;
	Q.push(pos(x - 1, y - 1, 0, 0));
	dp[0][x - 1][y - 1] = 0;
	cin >> x >> y;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int k = 0; k < 2; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				dp[k][i][j] = 99999999;
			}
		}
	}

	while (!Q.empty()) {
		tx = Q.front().x;
		ty = Q.front().y;
		ts = Q.front().s;
		td = Q.front().d;
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = tx + dir[i][0];
			ny = ty + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && td + 1 < dp[ts][nx][ny]) {
				if (map[nx][ny] == 0) {
					dp[ts][nx][ny] = td + 1;
					Q.push(pos(nx, ny, ts, td + 1));
				}
				else if (map[nx][ny] == 1 && ts == 0) {
					dp[1][nx][ny] = td + 1;
					Q.push(pos(nx, ny, 1, td + 1));
				}
			}
		}
	}

	if (dp[0][x - 1][y - 1] == 99999999 && dp[1][x - 1][y - 1] == 99999999)
		cout << -1 << endl;
	else
		cout << min(dp[0][x - 1][y - 1], dp[1][x - 1][y - 1]) << "\n";
	return 0;
}
