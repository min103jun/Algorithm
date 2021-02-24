#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string map[20];
int H, W, ret = 0, answer = 0;
int d[4][2][2] = {
	{{1, 0}, {0, 1}},
	{{0, 1}, {1, 1}},
	{{1, 0}, {1, 1}},
	{{1, 0}, {1, -1}}
};
vector<pair<int, int>> pos;

void init()
{
	ret = answer = 0;
	pos.clear();
}

void DFS(int index)
{
	if (ret == 0) {
		++answer;
		return;
	}
	else {
		int i;
		int x, y, nx1, ny1, nx2, ny2;
		for (i = index; i < pos.size(); i++) {
			if (map[pos[i].first][pos[i].second] == '.') {
				x = pos[i].first;
				y = pos[i].second;
				break;
			}
		}
		index = i + 1;
		for (i = 0; i < 4; i++) {
			nx1 = x + d[i][0][0];
			ny1 = y + d[i][0][1];
			nx2 = x + d[i][1][0];
			ny2 = y + d[i][1][1];
			if (nx1 >= 0 && nx2 >= 0 && ny1 >= 0 && ny2 >= 0 && nx1 < H && nx2 < H && ny1 < W && ny2 < W && map[nx1][ny1] == '.' && map[nx2][ny2] == '.') {
				map[x][y] = map[nx1][ny1] = map[nx2][ny2] = '#';
				ret -= 3;
				DFS(index);
				ret += 3;
				map[x][y] = map[nx1][ny1] = map[nx2][ny2] = '.';
			}
		}

	}

}

void solution()
{
	int i, j;

	cin >> H >> W;
	for (i = 0; i < H; i++) {
		cin >> map[i];
		for (j = 0; j < W; j++) {
			if (map[i][j] == '.') {
				++ret;
				pos.push_back(make_pair(i, j));
			}
		}
	}

	if (ret % 3 != 0)
		return;
	DFS(0);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, T;

	cin >> T;
	for (i = 0; i <= T; i++) {
		init();
		solution();
		cout << answer << endl;
	}
	return 0;
}
