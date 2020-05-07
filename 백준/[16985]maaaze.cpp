#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef struct pos {
	int x;
	int y;
	int z;
	int d;

	pos(int _x, int _y, int _z, int _d) : x(_x), y(_y), z(_z), d(_d) {};
}pos;

int map[5][5][5], cmap[5][5][5];
int rotate[5] = { 0, 0, 0, 0, 0 }, answer = 9999;
bool stackvisit[5] = {false, false, false, false, false};
queue<pos> Q;

bool check()
{
	int i, j, k, tx, ty, tz, td, nx, ny, nz;
	int dir[6][3] = { {0, -1, 0}, {0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {-1, 0, 0}, {1, 0, 0} };
	bool visit[5][5][5];

	memset(visit, false, sizeof(bool) * 5);
	for (i = 0; i < 5; i++) {
		memset(visit[i], false, sizeof(bool) * 5);
		for (j = 0; j < 5; j++) {
			memset(visit[i][j], false, sizeof(bool) * 5);
		}
	}

	Q.push(pos(0, 0, 0, 0));
	visit[0][0][0] = true;
	while (!Q.empty()) {
		tx = Q.front().x;
		ty = Q.front().y;
		tz = Q.front().z;
		td = Q.front().d;
		Q.pop();
		if (tx == 4 && ty == 4 && tz == 4) {
			answer = min(answer, td);
		}
		else {
			for (i = 0; i < 6; i++) {
				nx = tx + dir[i][0];
				ny = ty + dir[i][1];
				nz = tz + dir[i][2];
				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < 5 && ny < 5 && nz < 5 && visit[nx][ny][nz] == false && cmap[nx][ny][nz] == 1) {
					visit[nx][ny][nz] = true;
					Q.push(pos(nx, ny, nz, td + 1));
				}
			}
		}
	}

	return false;
}

void stack(int index, int cnt)
{
	if (cnt == 5) {
		check();
		return;
	}
	else {
		for (int i = 0; i < 5; i++) {
			if (stackvisit[i] == false) {
				stackvisit[i] = true;
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						cmap[index][j][k] = map[i][j][k];
					}
				}
				stack(index + 1, cnt + 1);
				stackvisit[i] = false;
			}
		}
	}
}

void rotatemap(int index)
{
	//90도씩 회전해 나간다.
	int i, j, tmap[5][5];

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			tmap[j][4 - i] = map[index][i][j];
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			map[index][i][j] = tmap[i][j];
		}
	}
}

void DFS(int index, int cnt)
{
	if (cnt == 5) {
		//판들을 일단 먼저 회전을 시킨후 -> 쌓기 시작한다.
		//이때 제일 위에 있는 (0, 0, 0) 의 value가 0이면 시작도 못하므로 backtracking한다.
		for (int i = 0; i < 5; i++) {
			if (map[i][0][0] == 1) {
				stackvisit[i] = true;
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						cmap[0][j][k] = map[i][j][k];
					}
				}
				stack(1, 1);
				stackvisit[i] = false;
			}
		};
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			rotatemap(index);
			DFS(index + 1, cnt + 1);
		}
		return;
	}
}

int main()
{
	int i, j, k;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				cin >> map[i][j][k];
			}
		}
	}

	for (i = 0; i < 4; i++) {
		rotatemap(0);
		DFS(1, 1);
	}

	if (answer == 9999)
		cout << -1 << endl;
	else
		cout << answer << endl;
	return 0;
}
