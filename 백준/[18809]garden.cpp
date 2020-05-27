#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int land[50][50];
int timeG[50][50], timeR[50][50];
bool visitG[50][50], visitR[50][50];
bool visit[2500];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int start, answer = 0, N, M, G, R;
vector<pair<int, int>> pos, gv, rv;
queue<pair<int, int>> gq, rq;

void check()
{
	int c_map[50][50], t = 0, cnt = 0;
	int i, j, sz;
	int tx, ty, nx, ny;

	memset(timeG, -1, sizeof(int) * N);
	memset(timeR, -1, sizeof(int) * N);
	memset(visitG, false, sizeof(bool) * N);
	memset(visitR, false, sizeof(bool) * N);
	for (i = 0; i < N; i++) {
		memset(timeG[i], -1, sizeof(int) * M);
		memset(timeR[i], -1, sizeof(int) * M);
		memset(visitG[i], false, sizeof(bool) * M);
		memset(visitR[i], false, sizeof(bool) * M);
		for (j = 0; j < M; j++)
			c_map[i][j] = land[i][j];
	}

	for (i = 0; i < G; i++) {
		gq.push(gv[i]);
		visitG[gv[i].first][gv[i].second] = true;
		timeG[gv[i].first][gv[i].second] = 0;
	}
	for (i = 0; i < R; i++) {
		rq.push(rv[i]);
		visitR[rv[i].first][rv[i].second] = true;
		timeR[rv[i].first][rv[i].second] = 0;
	}

	while (!gq.empty() || !rq.empty()) {
		++t;
		sz = gq.size();
		for (i = 0; i < sz; i++) {
			tx = gq.front().first;
			ty = gq.front().second;
			gq.pop();
			if (c_map[tx][ty] == 3)
				continue;
			for (j = 0; j < 4; j++) {
				nx = tx + dir[j][0];
				ny = ty + dir[j][1];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visitG[nx][ny] && c_map[nx][ny] != 0 && c_map[nx][ny] != 3 && timeR[nx][ny] == -1) {
					visitG[nx][ny] = true;
					timeG[nx][ny] = t;
					gq.push(make_pair(nx, ny));
				}
			}
		}

		sz = rq.size();
		for (i = 0; i < sz; i++) {
			tx = rq.front().first;
			ty = rq.front().second;
			rq.pop();
			if (c_map[tx][ty] == 3)
				continue;
			for (j = 0; j < 4; j++) {
				nx = tx + dir[j][0];
				ny = ty + dir[j][1];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visitR[nx][ny] && c_map[nx][ny] != 0 && c_map[nx][ny] != 3) {
					visitR[nx][ny] = true;
					timeR[nx][ny] = t;
					if(timeG[nx][ny] == timeR[nx][ny]) {
						++cnt;
						c_map[nx][ny] = 3;
					}
					else if (timeG[nx][ny] == -1) {
						rq.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

	answer = max(answer, cnt);
}
 
void dfsred(int index, int cnt)
{
	if (cnt == R) {
		check();
		return;
	}
	else {
		for (int i = index; i < pos.size(); i++) {
			if (visit[i] == false) {
				rv.push_back(pos[i]);
				visit[i] = true;
				dfsred(i + 1, cnt + 1);
				rv.erase(rv.end() - 1);
				visit[i] = false;
			}
		}
	}
}

void dfsgreen(int index, int cnt)
{
	if (cnt == G) {
		dfsred(0, 0);
		return;
	}
	else {
		for (int i = index; i < pos.size(); i++) {
			if (visit[i] == false) {
				gv.push_back(pos[i]);
				visit[i] = true;
				dfsgreen(i + 1, cnt + 1);
				gv.erase(gv.end() - 1);
				visit[i] = false;
			}
		}
	}
}

int main()
{
	int i, j, cnt = 0;

	cin >> N >> M >> G >> R;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> land[i][j];
			if (land[i][j] == 2) {
				pos.push_back(make_pair(i, j));
				++cnt;
			}
		}
	}
	memset(visit, false, sizeof(bool) * cnt);
	dfsgreen(0, 0);

	cout << answer << endl;
	return 0;
}
