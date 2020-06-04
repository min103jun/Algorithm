#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

typedef struct info {
	int from;
	int to;
	int d;

	info(int _f, int _t, int _d) {
		from = _f;
		to = _t;
		d = _d;
	}
}info;
int N, M;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
map<pair<int, int>, int> distanceset;
vector<info> graph;
int land[10][10];
bool visit[10][10];
queue<pair<int, int>> Q;
int parent[7], num = 0;

void numbering()
{
	int i, j, k;
	int tx, ty, nx, ny;
	memset(visit, false, sizeof(bool) * N);
	for (i = 0; i < N; i++) {
		memset(visit[i], false, sizeof(bool) * M);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (visit[i][j] == false && land[i][j] != 0) {
				++num;
				visit[i][j] = true;
				Q.push(make_pair(i, j));
				while (!Q.empty()) {
					tx = Q.front().first;
					ty = Q.front().second;
					Q.pop();
					land[tx][ty] = num;
					for (k = 0; k < 4; k++) {
						nx = tx + dir[k][0];
						ny = ty + dir[k][1];
						if (nx >= 0 && ny >= 0 && nx < N && ny < M && visit[nx][ny] == false && land[nx][ny] != 0) {
							visit[nx][ny] = true;
							Q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}

void distance()
{
	int i, j, k, l, d, a, b;
	int tx, ty;
	pair<int, int> key;
	bool flag;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (land[i][j] != 0) {
				//0이 아니면 섬이다.
				for (k = 0; k < 4; k++) {
					tx = i + dir[k][0];
					ty = j + dir[k][1];
					if (tx >= 0 && ty >= 0 && tx < N && ty < M && land[tx][ty] == 0) {
						//해당 방향이 바다면 나갈 수 있다.
						flag = false;
						while (true) {
							if (tx < 0 || ty < 0 || tx >= N || ty >= M) {
								flag = true;
								break;
							}
							if (land[tx][ty] != 0) {
								d = abs(tx - i) + abs(ty - j) - 1;
								if (d > 1) {
									a = min(land[i][j], land[tx][ty]);
									b = max(land[i][j], land[tx][ty]);
									key = make_pair(a, b);
									if (distanceset.find(key) == distanceset.end())
										distanceset[key] = d;
									else
										distanceset[key] = min(distanceset[key], d);
								}
								break;
							}
							tx += dir[k][0];
							ty += dir[k][1];
						}
					}
				}
			}
		}
	}
}

bool compare(const info& a, const info& b)
{
	return a.d < b.d;
}

int findparent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = findparent(parent[x]);
}
int main()
{
	int i, j, answer = 0;
	int a, b;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> land[i][j];

	numbering();
	distance();
	for (map<pair<int, int>, int>::iterator iter = distanceset.begin(); iter != distanceset.end(); ++iter) {
		graph.push_back(info(iter->first.first, iter->first.second, iter->second));
	}
	sort(graph.begin(), graph.end(), compare);

	for (i = 1; i <= num; i++)
		parent[i] = i;

	for (i = 0; i < graph.size(); i++) {
		a = findparent(graph[i].from);
		b = findparent(graph[i].to);
		if (a != b) {
			answer += graph[i].d;
			parent[a] = b;
		}
	}

	a = findparent(1);
	for (i = 2; i <= num; i++) {
		if (findparent(i) != a) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << answer << endl;
	return 0;
}
