#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct fish {
	int x;
	int y;
	int d;
	bool live;
	fish(int _x, int _y, int _d, bool _l) : x(_x), y(_y), d(_d), live(_l) {};
}fish;

vector<fish> fisharr(17, fish(0, 0, 0, true));
int dir[8][2] = { {-1, 0},{-1, -1},{0, -1},{1, -1},{1, 0},{1,1},{0, 1},{-1, 1} };
int answer = 0;

void DFS(int x, int y, int d, int score, int map[][4])
{
	int i, j, nd;
	int px, py, nx, ny, temp;

	answer = max(answer, score);
	//물고기의 이동
	for (i = 1; i <= 16; i++) {
		if (fisharr[i].live) {
			px = fisharr[i].x;
			py = fisharr[i].y;
			for (j = 0; j < 8; j++) {
				nd = (fisharr[i].d + j) % 8;
				nx = px + dir[nd][0];
				ny = py + dir[nd][1];
				if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && (nx != x || ny != y)) {
					if (map[nx][ny] == 0) {
						//비어있는 칸이면 그냥 가면 된다.
						fisharr[i] = fish(nx, ny, nd, true);
						map[nx][ny] = i;
						map[px][py] = 0;
					}
					else {
						//다른 생선이 있다면 위치를 바꾸면 된다.
						temp = map[nx][ny];//그 위치에 있는 생선의 번호
						fisharr[temp] = fish(px, py, fisharr[temp].d, true);
						fisharr[i] = fish(nx, ny, nd, true);
						map[nx][ny] = i;
						map[px][py] = temp;
					}
					break;
				}
			}
		}
	}

	//상어의 이동
	for (i = 0; i < 3; i++) {
		x += dir[d][0];
		y += dir[d][1];
		if (x >= 0 && y >= 0 && x < 4 && y < 4 && map[x][y] > 0) {
			temp = map[x][y];
			map[x][y] = 0;
			fisharr[temp].live = false;
			DFS(x, y, fisharr[temp].d, score + temp, map);
			fisharr[temp].live = true;
			map[x][y] = temp;
		}
	}
}

int main()
{
	int i, j, a, b, score;
	int map[4][4];

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			cin >> a >> b;
			fisharr[a] = fish(i, j, b - 1, true);
			map[i][j] = a;
		}
	}

	fisharr[map[0][0]].live = false;
	score = map[0][0];
	map[0][0] = 0;
	DFS(0, 0, fisharr[score].d, score, map);

	cout << answer << endl;

	return 0;
}
