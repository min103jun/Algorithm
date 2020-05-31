//첫번째 풀이 - dfs로 그려가며 바로바로 리턴하는 
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

//두번째 방식 - 일단 d1, d2를 정해두고 그려보며 판단하는 방식
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int answer, N;
int map[20][20];
int dir[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
bool visit[101];

bool circle(int x, int y, int d1, int d2)
{
	int tx = x;
	int ty = y;

	for (int i = 0; i < 3; i++) {
		if (i == 0 || i == 2) {
			tx += (dir[i][0] * d1);
			ty += (dir[i][1] * d1);
		}
		else {
			tx += (dir[i][0] * d2);
			ty += (dir[i][1] * d2);
		}
		if (tx < 0 || ty < 0 || tx >= N || ty >= N)
			return false;
	}

	return true;
}

void check(int x, int y, int d1, int d2)
{
	int i, j, k, d, cnt = 0;
	int tx, ty, nx, ny;

	memset(visit, false, sizeof(bool) * 101);
	tx = x;
	ty = y;
	for (i = 0; i < 4; i++) {
		if (i == 0 || i == 2)
			d = d1;
		else
			d = d2;
		for (j = 0; j < d; j++) {
			tx += dir[i][0];
			ty += dir[i][1];
			if (visit[map[tx][ty]] == false) {
				visit[map[tx][ty]] = true;
				++cnt;
			}
			else
				return;
		}
	}
	answer = max(cnt, answer);
}

void solution()
{
	int i, j, d1, d2;

	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (d1 = 1; d1 < N; d1++) {
		for (d2 = 1; d2 < N; d2++) {
			for (i =0; i < N - 2; i++) {
				for (j = 1; j < N - 1; j++) {
					if (circle(i, j, d1, d2)) {
						check(i, j, d1, d2);
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++) {
		answer = 0;
		solution();
		if(answer == 0)
			cout << "#" << i << " -1" << endl;
		else
			cout << "#" << i << " " << answer << endl;
	}
}
