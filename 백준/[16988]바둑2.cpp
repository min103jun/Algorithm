#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[20][20], N, M, answer = 0;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<pair<int, int>> blank, enemy;
queue<pair<int, int>> Q;

void check()
{
	int i, j, sz, t_answer = 0, cnt = 0;
	int tx, ty, nx, ny;
	bool visit[20][20], flag;
	
	memset(visit, false, sizeof(bool) * N);
	for (i = 0; i < N; i++)
		memset(visit[i], false, sizeof(bool) * M);

	sz = enemy.size();
	for (i = 0; i < sz; i++) {
		if (visit[enemy[i].first][enemy[i].second] == false) {
			flag = false;
			cnt = 0;
			Q.push(enemy[i]);
			visit[enemy[i].first][enemy[i].second] = true;
			while (!Q.empty()) {
				++cnt;
				tx = Q.front().first;
				ty = Q.front().second;
				Q.pop();
				for (j = 0; j < 4; j++) {
					nx = tx + dir[j][0];
					ny = ty + dir[j][1];
					if (nx >= 0 && ny >= 0 && nx < N && ny < M && visit[nx][ny] == false) {
						//일단 바둑판 안
						if (map[nx][ny] == 1)
							continue;
						else if (map[nx][ny] == 0) {
							flag = true;
							//둘러 쌓여있지 않음
						}
						else {
							visit[nx][ny] = true;
							Q.push(make_pair(nx, ny));
						}
					}
				}
			}
			if (flag == false)
				t_answer += cnt;
		}
	}

	answer = max(answer, t_answer);
}

int main()
{
	int i, j, sz;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				blank.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				enemy.push_back(make_pair(i, j));
			}
		}
 	}

	sz = blank.size();
	for (i = 0; i < sz - 1; i++) {
		map[blank[i].first][blank[i].second] = 1;
		for (j = i + 1; j < sz; j++) {
			map[blank[j].first][blank[j].second] = 1;
			check();
			map[blank[j].first][blank[j].second] = 0;
		}
		map[blank[i].first][blank[i].second] = 0;
	}

	cout << answer << endl;

	return 0;
}
