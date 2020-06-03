#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int map[125][125];
int dp[125][125];
queue<pair<int, int>> Q;

int solution()
{
	int i, j;
	int tx, ty, nx, ny;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
			dp[i][j] = 99999999;
		}
	}

	Q.push(make_pair(0, 0));
	dp[0][0] = map[0][0];
	while (!Q.empty()) {
		tx = Q.front().first;
		ty = Q.front().second;
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = tx + dir[i][0];
			ny = ty + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && dp[tx][ty] + map[nx][ny] < dp[nx][ny]) {
				dp[nx][ny] = dp[tx][ty] + map[nx][ny];
				Q.push(make_pair(nx, ny));
			}
		}
	}
	return dp[N - 1][N - 1];
}

int main()
{
	int i = 1;

	while (true) {
		cin >> N;
		if (N == 0)
			break;
		cout <<"Problem " << i << ": "<< solution() << endl;
		++i;
	}
	return 0;
}
