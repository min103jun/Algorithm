#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[50][50];
bool uncloud[50][50] = { false }; //구름에 소멸된 곳에는 다시 구름생성x
int dir[8][2] = { {0, -1},{-1, -1},{-1, 0},{-1, 1},{0, 1},{1, 1},{1, 0},{1, -1} };
vector<pair<int, int>> cloud;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, s, d, d1, d2;
	int x, y, idx=0, cnt = 0, answer =0;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	cloud.push_back(make_pair(N - 1, 0)); cloud.push_back(make_pair(N - 1, 1)); cloud.push_back(make_pair(N - 2, 0)); cloud.push_back(make_pair(N - 2, 1));
	while(idx < M) {
		//구름을 d방향으로 s만큼 이동
		cin >> d >> s;
		for (i = 0; i < cloud.size(); i++) {
			x = cloud[i].first;
			y = cloud[i].second;
			for (j = 0; j < s; j++) {
				x += dir[d - 1][0];
				y += dir[d - 1][1];
				if (x < 0) x = N - 1; if (x == N) x = 0;
				if (y < 0) y = N - 1; if (y == N) y = 0;
			}
			cloud[i].first = x;
			cloud[i].second = y;
		}

		//각 칸에서 1이 증가
		memset(uncloud, false, sizeof(bool) * N);
		for (i = 0; i < N; i++)
			memset(uncloud[i], false, sizeof(bool) * N);
		for (i = 0; i < cloud.size(); i++) {
			++map[cloud[i].first][cloud[i].second];
			uncloud[cloud[i].first][cloud[i].second] = true;
		}

		//구름에 의해 1이증가한 곳에 물복사버그 마법 시전.
		for (i = 0; i < cloud.size(); i++) {
			cnt = 0;
			for (j = 1; j < 8; j += 2) {
				x = cloud[i].first + dir[j][0];
				y = cloud[i].second + dir[j][1];
				if (x >= 0 && y >= 0 && x < N && y < N && map[x][y] > 0)
					++cnt;
			}
			map[cloud[i].first][cloud[i].second] += cnt;
		}
		cloud.clear();

		//물의 양이 2이상이고, 구름이 소명되지 않은 곳에 구름이 생성됨.
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (map[i][j] >= 2 && !uncloud[i][j]) {
					cloud.push_back(make_pair(i, j));
					map[i][j] -= 2;
				}
			}
		}
		++idx;
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			answer += map[i][j];

	cout << answer << endl;
	return 0;
}
