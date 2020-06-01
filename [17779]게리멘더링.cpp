//(1) DFS로 마름모를 만듬
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int answer = 99999999, N, x, y, map[21][21], landing[21][21];
bool visit[21][21];
vector<pair<int, int>> pos;

void check(int d1, int d2)
{
	int i, j, max_ans = 0, min_ans = 99999999;
	int score[5] = { 0, 0, 0, 0, 0 };
	bool flag = false;
	memset(landing, 0, sizeof(int) * (N + 1));
	for (i = 1; i <= N; i++)
		memset(landing[i], 0, sizeof(int) * (N + 1));

	for (i = 0; i < pos.size(); i++) {
		landing[pos[i].first][pos[i].second] = 5;
	}
	
	for (i = x + 1; i <= x + d1 + d2 - 1; i++) {
		flag = false;
		for (j = 1; j <= N; j++) {
			if (landing[i][j] == 5)
				flag = !flag;
			if (flag)
				landing[i][j] = 5;
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (landing[i][j] == 5)
				score[0] += map[i][j];
			else if (1 <= i && i < x + d2 && 1 <= j && j <= y) {
				landing[i][j] = 1;
				score[1] += map[i][j];
			}
			else if (1 <= i && i <= x + d1 && y < j && j <= N) {
				landing[i][j] = 2;
				score[2] += map[i][j];
			}
			else if (x + d2 <= i && i <= N && 1 <= j && j < y - d2 + d1) {
				landing[i][j] = 3;
				score[3] += map[i][j];
			}
			else if (x + d1 <= i && i <= N && y - d2 + d1 <= j && j <= N) {
				landing[i][j] = 4;
				score[4] += map[i][j];
			}
		}
	}

	min_ans = score[0];
	max_ans = score[0];
	for (i = 1; i < 5; i++) {
		min_ans = min(min_ans, score[i]);
		max_ans = max(max_ans, score[i]);
	}

	answer = min(answer, max_ans - min_ans);
}

void DFS(int tx, int ty, int d1, int d2, int d3, int d4, int d)
{
	if (tx > 0 && ty > 0 && tx <= N && ty <= N && !visit[tx][ty]) {
		visit[tx][ty] = true;
		pos.push_back(make_pair(tx, ty));
		if (d == 0) {
			DFS(tx + 1, ty + 1, d1 + 1, d2, d3, d4, 0);
			DFS(tx + 1, ty - 1, d1, d2 + 1, d3, d4, 1); 
		}
		else if (d == 1) {
			DFS(tx + 1, ty - 1, d1, d2 + 1, d3, d4, 1);
			DFS(tx - 1, ty - 1, d1, d2, d3 + 1, d4, 2);
		}
		else if (d == 2) {
			if(d3 < d1)
				DFS(tx - 1, ty - 1, d1, d2, d3 + 1, d4, 2);
			else
				DFS(tx - 1, ty + 1, d1, d2, d3, d4 + 1, 3);
		}
		else {
			if(d4 < d2)
				DFS(tx - 1, ty + 1, d1, d2, d3, d4 + 1, 3);
			else {
				check(d1, d2);
			}

		}
		pos.erase(pos.end() - 1);
		visit[tx][ty] = false;
	}
}

int main()
{
	int i, j;

	cin >> N;
	memset(visit, false, sizeof(bool) * (N + 1));
	for (i = 1; i <= N; i++) {
		memset(visit, false, sizeof(bool) * (N + 1));
		for (j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (i = 1; i <= N - 2; i++) {
		for (j = 2; j <= N - 1; j++) {
			x = i; y = j;
			DFS(i + 1, j + 1, 1, 0, 0, 0, 0);
		}
	}

	cout << answer << endl;

	return 0;
}
