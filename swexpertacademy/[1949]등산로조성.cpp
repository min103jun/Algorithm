#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, answer = 0, max_height = 0;
int map[8][8];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool visit[8][8];

void init()
{
	answer = max_height = 0;
	memset(map, 0, sizeof(bool) * 8);
	memset(visit, false, sizeof(bool) * false);
	for (int i = 0; i < 8; i++) {
		memset(map[i], 0, sizeof(int) * 8);
		memset(visit[i], false, sizeof(bool) * 8);
	}
}

void DFS(int x, int y, int state, int d)
{
	answer = max(d, answer);
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
			if (map[nx][ny] < map[x][y]) {
				visit[nx][ny] = true;
				DFS(nx, ny, state, d + 1);
				visit[nx][ny] = false;
			}
			else {
				//갈 수 없는 지형이면 깍아서 가야하는데.. 이미 깍은 상태면 못간다.
				if (state == 1) 
					continue;
				for (int j = 1; j <= K; j++) {
					//하나씩 깍아서 가본다.
					int temp = map[nx][ny];
					int newland = map[nx][ny] - j;

					if (newland < map[x][y]) {
						//깍은 지형이 이제 갈 수있게 된다면
						visit[nx][ny] = true;
						map[nx][ny] = newland;
						DFS(nx, ny, 1, d + 1);
						map[nx][ny] = temp;
						visit[nx][ny] = false;
					}
				}
			}
		}
	}
}

void solution()
{
	int i, j;

	cin >> N >> K;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
			max_height = max(max_height, map[i][j]);
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == max_height && !visit[i][j]) {
				visit[i][j] = true;
				DFS(i, j, 0, 1);
				visit[i][j] = false;
			}
		}
	}

	return;
}

int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++) {
		init();
		solution();
		cout << "#" << i << " " << answer << endl;
	}
}
