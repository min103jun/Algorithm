#include <iostream>

using namespace std;

int index[7] = { 0, 1, 2, 3, 4, 5, 6};
int score[7] = {0, 0, 0, 0, 0 , 0, 0};
int map[20][20];

int main()
{
	int i, j, N, M, x, y, cmd, n, temp;
	int nx, ny;
	int dir[5][2] = { {0,0}, {0, 1}, {0, -1}, {-1, 0}, {1,0}};
	cin >> N >> M >> x >> y >> cmd;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> map[i][j];

	for (i = 0; i < cmd; i++) {
		cin >> n;
		nx = x + dir[n][0];
		ny = y + dir[n][1];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			x = nx; y = ny;
			temp = index[1];
			if (n == 1) {
				index[1] = index[4];
				index[4] = index[6];
				index[6] = index[3];
				index[3] = temp;
			}
			else if (n == 2) {
				index[1] = index[3];
				index[3] = index[6];
				index[6] = index[4];
				index[4] = temp;
			}
			else if (n == 3) {
				index[1] = index[5];
				index[5] = index[6];
				index[6] = index[2];
				index[2] = temp;
			}
			else {
				index[1] = index[2];
				index[2] = index[6];
				index[6] = index[5];
				index[5] = temp;
			}

			if (map[x][y] == 0) {
				map[x][y] = score[index[6]];
			}
			else {
				score[index[6]] = map[x][y];
				map[x][y] = 0;
			}
			cout << score[index[1]] << "\n";
		}
	}

	return 0;
}
