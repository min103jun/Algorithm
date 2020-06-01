#include <iostream>
#include <queue>

using namespace std;

typedef struct pos {
	int x;
	int y;
	int d;

	pos(int _x, int _y, int _d) : x(_x), y(_y), d(_d){};
}pos;

int map[100][100];
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
bool visit[4][100][100];
queue<pos> Q;
int main()
{
	int i, j, k, N, M, sz, t = 0, ex, ey, ed;
	int tx, ty, td, tl, nx, ny, nd;

	cin >> N >> M;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++)
				visit[i][j][k] = false;
		}
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> map[i][j];
	cin >> tx >> ty >> td;
	Q.push(pos(tx - 1, ty - 1, td - 1));
	visit[td - 1][tx - 1][ty - 1] = true;
	cin >> ex >> ey >> ed;
	ex -= 1; ey -= 1; ed -= 1;

	while (!Q.empty()) {
		sz = Q.size();
		for (i = 0; i < sz; i++) {
			tx = Q.front().x;
			ty = Q.front().y;
			td = Q.front().d;
			Q.pop();
			if (tx == ex && ty == ey && td == ed) {
				cout << t << endl;
				return 0;
			}
			
			for (j = 1; j <= 3; j++) {
				nx = tx + (dir[td][0] * j);
				ny = ty + (dir[td][1] * j);
				if (map[nx][ny] == 1)
					break;
				if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visit[td][nx][ny]) {
					visit[td][nx][ny] = true;
					Q.push(pos(nx, ny, td));
				}
			}

			if (td == 0) nd = 2;
			else if (td == 1) nd = 3;
			else if (td == 2) nd = 1;
			else if (td == 3) nd = 0;
			if (visit[nd][tx][ty] == false) {
				visit[nd][tx][ty] = true;
				Q.push(pos(tx, ty, nd));
			}
			if (td == 0) nd = 3;
			else if (td == 1) nd = 2;
			else if (td == 2) nd = 0;
			else if (td == 3) nd = 1;
			if (visit[nd][tx][ty] == false) {
				visit[nd][tx][ty] = true;
				Q.push(pos(tx, ty, nd));
			}
		}
		++t;
	}
	return 0;
}
