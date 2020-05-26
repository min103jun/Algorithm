#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool map[101][101];
int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

void dragon_curve(int x, int y, int d, int g)
{
	vector<int> curve;
	int i, j, sz, tx, ty, nd;

	map[x][y] = true;
	curve.push_back(d);
	tx = x + dir[d][0];
	ty = y + dir[d][1];
	map[tx][ty] = true;
	for (i = 0; i < g; i++) {
		sz = curve.size();
		for (j = sz - 1; j >= 0; j--) {
			nd = (curve[j] + 1) % 4;
			curve.push_back(nd);
			tx += dir[nd][0];
			ty += dir[nd][1];
			map[tx][ty] = true;
		}
	}
}

int main()
{
	int N, i, j, answer = 0;
	int x, y, d, g;

	memset(map, false, sizeof(bool) * 101);
	for (i = 0; i <= 100; i++)
		memset(map[i], false, sizeof(bool) * 101);

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> y >> x >> d >> g;
		dragon_curve(x, y, d, g);
	}

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				++answer;
		}
	}

	cout << answer << endl;
	return 0;
}
