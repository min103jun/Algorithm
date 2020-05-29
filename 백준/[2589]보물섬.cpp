#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 9999

using namespace std;


char map[50][50];
int dp[50][50];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<pair<int, int>> landpos;
queue<pair<int, int>> Q;

int main()
{
	int i, j, k, sz = 0, N, M, answer = 0;
	int tx, ty, nx, ny;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				landpos.push_back(make_pair(i, j));
				++sz;
			}
		}
	}

	for (i = 0; i < sz; i++) {
		/*
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				dp[j][k] = 9999;
			}
		}
		*/
		memset(dp, MAX, sizeof(int) * N);
		for (j = 0; j < N; j++)
			memset(dp[j], MAX, sizeof(int) * M);
		Q.push(landpos[i]);
		dp[landpos[i].first][landpos[i].second] = 0;
		while (!Q.empty()) {
			tx = Q.front().first;
			ty = Q.front().second;
			Q.pop();
			answer = max(answer, dp[tx][ty] + 1);
			for (j = 0; j < 4; j++) {
				nx = tx + dir[j][0];
				ny = ty + dir[j][1];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] == 'L' && dp[tx][ty] + 1 < dp[nx][ny]) {
					dp[nx][ny] = dp[tx][ty] + 1;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}

	cout << answer - 1 << endl;

	return 0;
}
