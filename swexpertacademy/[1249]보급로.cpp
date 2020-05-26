#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

int N;
int map[100][100], dp[100][100];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
queue<pair<int, int>> Q;

int solution()
{
	int i, j;
	int tx, ty, nx, ny;
	string str;

	cin >> N;
	memset(map, 0, sizeof(int) * N);
	for (i = 0; i < N; i++) {
		memset(map[i], 0, sizeof(int) * N);
		cin >> str;
		for (j = 0; j < N; j++) {
			map[i][j] = stoi(str.substr(j, 1));
			dp[i][j] = 9999999;
		}
	}

	dp[0][0] = map[0][0];
	Q.push(make_pair(0, 0));
	while (!Q.empty()) {
		tx = Q.front().first;
		ty = Q.front().second;
		Q.pop();
		for (i = 0; i < 4; i++) {
			nx = tx + dir[i][0];
			ny = ty + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (map[nx][ny] + dp[tx][ty] < dp[nx][ny]) {
					dp[nx][ny] = map[nx][ny] + dp[tx][ty];
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return dp[N - 1][N - 1];
}

int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++) 
		cout << "#" << i << " " << solution() << endl;
	
	return 0;
}
