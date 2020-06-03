#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int dis[101];
bool visit[101];
vector<int> graph[101];
queue<int> Q;

int main()
{
	int i, j, N, M, answer = 99999999, index = 0;
	int x, y, k, l, sz, sum = 0;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (i = 1; i <= N; i++) {
		memset(visit, false, sizeof(bool) * (N + 1));
		memset(dis, 0, sizeof(int) * (N + 1));
		visit[i] = true;
		Q.push(i);
		k = 1;
		sum = 0;
		while (!Q.empty()) {
			sz = Q.size();
			for (j = 0; j < sz; j++) {
				x = Q.front();
				Q.pop();
				for (l = 0; l < graph[x].size(); l++) {
					if (visit[graph[x][l]] == false) {
						visit[graph[x][l]] = true;
						dis[graph[x][l]] = k;
						Q.push(graph[x][l]);
					}
				}
			}
			++k;
		}
		for (j = 1; j <= N; j++) {
			sum += dis[j];
		}
		if (sum < answer) {
			answer = sum;
			index = i;
		}
	}

	cout << index << endl;
	return 0;
}
