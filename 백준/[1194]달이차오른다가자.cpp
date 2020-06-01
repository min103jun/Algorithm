#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

typedef struct pos {
	int x;
	int y;
	int key;

	pos(int _x, int _y, int _k) : x(_x), y(_y), key(_k) {};
}pos;

map<char, int> keyset = { {'a', 1}, {'A', 1}, {'b', 2}, {'B', 2}, {'c', 4}, {'C', 4}, 
			{'d', 8}, {'D', 8}, {'e', 16}, {'E', 16}, {'f', 32}, {'F', 32} };
char board[50][50];
bool visit[64][50][50];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
queue<pos> Q;

int main()
{
	int i, j, k, sz, tx, ty, tk, nx, ny;
	int N, M;
	pair<int, int> end;
	cin >> N >> M;
	for (i = 0; i < 64; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < M; k++)
				visit[i][j][k] = false;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0') {
				board[i][j] = '.';
				Q.push(pos(i, j, 0));
				visit[0][i][j] = true;
			}
		}
	}

	k = 0;
	while (!Q.empty()) {
		sz = Q.size();
		for (i = 0; i < sz; i++) {
			tx = Q.front().x;
			ty = Q.front().y;
			tk = Q.front().key;
			Q.pop();
			if (board[tx][ty] == '1') {
				cout << k << endl;
				return 0;
			}

			for (j = 0; j < 4; j++) {
				nx = tx + dir[j][0];
				ny = ty + dir[j][1];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visit[tk][nx][ny]) {
					if (board[nx][ny] == '.' || board[nx][ny] == '1') {
						visit[tk][nx][ny] = true;
						Q.push(pos(nx, ny, tk));
					}
					else if ('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
						if (visit[tk | keyset[board[nx][ny]]][nx][ny] == false) {
							visit[tk | keyset[board[nx][ny]]][nx][ny] = true;
							Q.push(pos(nx, ny, tk | keyset[board[nx][ny]]));
						}
					}
					else if ('A' <= board[nx][ny] && board[nx][ny] <= 'F') {
						if ((tk & keyset[board[nx][ny]]) != 0) {
							visit[tk][nx][ny] = true;
							Q.push(pos(nx, ny, tk));
						}
					}
				}
			}
		}
		++k;
	}

	cout << -1 << endl;
	return 0;
}
