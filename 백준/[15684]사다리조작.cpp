#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 9999
using namespace std;

int N, M, H, answer = MAX, sz = 0;
bool map[30][10];
vector<pair<int, int>> pos;

void check(int cnt)
{
	int i, j;
	int ty;

	for (j = 0; j < N; j++) {
		ty = j;
		for (i = 0; i < H; i++) {
			if (map[i][ty])
				++ty;
			else if (map[i][ty - 1])
				--ty;
		}
		if (j != ty)
			return;
	}

	answer = min(answer, cnt);
	if (answer == 0) {
		cout << 0 << endl;
		exit(0);
	}
}

void DFS(int index, int cnt)
{
	if (cnt > 3)
		return;

	if (cnt < answer) {
		check(cnt);
		for (int i = index; i < sz; i++) {
			int x = pos[i].first, y = pos[i].second;
			if (map[x][y] || map[x][y - 1] || map[x][y + 1])
				continue;
			map[x][y] = true;
			DFS(i + 1, cnt + 1);
			map[x][y] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, n, h;

	cin >> N >> M >> H;
	memset(map, false, sizeof(bool) * H);
	for (i = 0; i < N; i++)
		memset(map[i], false, sizeof(bool) * N);

	for (i = 0; i < M; i++) {
		cin >> h >> n;
		map[h - 1][n - 1] = true;
	}
	for (i = 0; i < H; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == false) {
				pos.push_back(make_pair(i, j));
				++sz;
			}
		}
	}
	DFS(0, 0);
	if (answer == MAX)
		cout << -1 << endl;
	else
		cout << answer << endl;

	return 0;
}