//중복해서 갈 수 있다. 그래서 플로이드와샬을 써서 각 점에서 최소거리를 구해주었다.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, answer = 99999999;
int d[10][10];
bool visit[10] = {false};

void DFS(int pos, int dis, int  cnt)
{
	if (cnt == N) {
		answer = min(answer, dis);
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!visit[i] && d[pos][i] != 0) {
				visit[i] = true;
				DFS(i, dis + d[pos][i], cnt + 1);
				visit[i] = false;
			}
		}
	}
}
int main()
{
	int i, j, k;

	cin >> N >> K;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> d[i][j];

	for (k = 0; k < N; k++) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	visit[K] = true;
	DFS(K, 0, 1);
	cout << answer << endl;
	return 0;
}
