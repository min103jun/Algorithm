#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct virus {
	int x;
	int y;
	int m;
	virus(int _x, int _y, int _m) : x(_x), y(_y), m(_m) {};
}virus;

int map[51][51], x, y;
vector<int> vaccum;

void rotate()
{
	int i, j;

	for (i = vaccum[0] - 1; i >= 1; i--)
		map[i][0] = map[i - 1][0];
	for (i = 0; i < y - 1; i++)
		map[0][i] = map[0][i + 1];
	for (i = 0; i < vaccum[0]; i++)
		map[i][y - 1] = map[i + 1][y - 1];
	for (i = y - 1; i >= 2; i--)
		map[vaccum[0]][i] = map[vaccum[0]][i - 1];
	map[vaccum[0]][1] = 0;

	for (i = vaccum[1] + 1; i < x - 1; i++)
		map[i][0] = map[i + 1][0];
	for (i = 0; i < y - 1; i++)
		map[x - 1][i] = map[x - 1][i + 1];
	for (i = x - 1; i > vaccum[1]; i--)
		map[i][y - 1] = map[i - 1][y - 1];
	for (i = y - 1; i >= 2; i--)
		map[vaccum[1]][i] = map[vaccum[1]][i - 1];
	map[vaccum[1]][1] = 0;
}

int main()
{
	queue<virus> virusarr;
	int i, j, k, l, temp, T, answer = 0;
	int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	scanf("%d %d %d", &x, &y, &T);
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1)
				vaccum.push_back(i);
		}
	}

	for (i = 0; i < T; i++) {
		//1. 바이러스 위치파악
		for (j = 0; j < x; j++) {
			for (k = 0; k < y; k++) {
				if (0 < map[j][k] && map[j][k] < 5) {
					continue;
				}
				if (map[j][k] > 4) {
					temp = map[j][k];
					map[j][k] = 0;
					int cnt = 0;
					for (l = 0; l < 4; l++) {
						int tempx = j + dir[l][0];
						int tempy = k + dir[l][1];
						if (tempx < 0 || tempy < 0 || tempx >= x || tempy >= y || (map[tempx][tempy] == -1))
							continue;
						cnt++;
						virusarr.push(virus(tempx, tempy, temp / 5));
					}
					virusarr.push(virus(j, k, temp - ((temp / 5) * cnt)));
				}
			}
		}

		//2. 바이러스 확산 합 구하기
		while (!virusarr.empty()) {
			map[virusarr.front().x][virusarr.front().y] += virusarr.front().m;
			virusarr.pop();
		}

		//3. 확산
		rotate();
	}

	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (map[i][j] > 0)
				answer += map[i][j];
		}
	}
	printf("%d\n", answer);

	return 0;
}
