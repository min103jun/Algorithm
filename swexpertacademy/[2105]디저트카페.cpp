#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, answer = 0, map[20][20];
int dir[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
bool visit[101];

void init()
{
	answer = 0;
	memset(visit, false, sizeof(bool) * 101);
}

void DFS(int x, int y, int d1, int d2, int d3, int d4, int d, int cnt)
{
	if (x >= 0 && y >= 0 && x < N && y < N && !visit[map[x][y]]) {
		visit[map[x][y]] = true;
		if (d == 0) {
			DFS(x + dir[0][0], y + dir[0][1], d1 + 1, d2, d3, d4, 0, cnt + 1);
			DFS(x + dir[1][0], y + dir[1][1], d1, d2 + 1, d3, d4, 1, cnt + 1);
		}
		else if (d == 1) {
			DFS(x + dir[1][0], y + dir[1][1], d1, d2 + 1, d3, d4, 1, cnt + 1);
			DFS(x + dir[2][0], y + dir[2][1], d1, d2, d3 + 1, d4, 2, cnt + 1);
		}
		else if (d == 2) {
			if (d3 < d1)
				DFS(x + dir[2][0], y + dir[2][1], d1, d2, d3 + 1, d4, 2, cnt + 1);
			else
				DFS(x + dir[3][0], y + dir[3][1], d1, d2, d3, d4 + 1, 3, cnt + 1);
		}
		else {
			if (d4 < d2)
				DFS(x + dir[3][0], y + dir[3][1], d1, d2, d3, d4 + 1, 3, cnt + 1);
			else
				answer = max(answer, cnt);
		}
		visit[map[x][y]] = false;
	}
}

void solution()
{
	int i, j;

	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> map[i][j];

	for (i = 0; i < N - 2; i++) {
		for (j = 1; j < N - 1; j++) {
			DFS(i + 1, j + 1, 1, 0, 0, 0, 0, 1);
		}
	}
}

int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++) {
		init();
		solution();
		if (answer == 0)
			cout << "#" << i << " -1" << "\n";
		else
			cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}
