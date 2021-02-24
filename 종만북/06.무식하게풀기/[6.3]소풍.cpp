#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool friends[10][10];
bool visit[10];
int n, m, answer = 0;

void init()
{
	answer = 0;
	memset(visit, false, sizeof(bool) * 10);
	memset(friends, false, sizeof(bool) * 10);
	for (int i = 0; i < 10; i++)
		memset(friends[i], false, sizeof(bool) * 10);
}

void DFS(int cnt)
{
	if (cnt == n / 2) {
		++answer;
		return;
	}
	else {
		int i, num;
		for (i = 0; i < n; i++) {
			if (!visit[i]) {
				num = i;
				break;
			}
		}

		for (i = 0; i < n; i++) {
			if (!visit[num] && !visit[i] && friends[num][i]) {
				visit[num] = visit[i] = true;
				DFS(cnt + 1);
				visit[num] = visit[i] = false;
			}
		}
	}
}

void solution()
{
	int i;
	int a, b;

	cin >> n >> m;

	for (i = 0; i < m; i++) {
		cin >> a >> b;
		friends[a][b] = friends[b][a] = true;
	}

	for (i = 0; i < n; i++) {
		if (friends[0][i]) {
			visit[0] = visit[i] = true;
			DFS(1);
			visit[0] = visit[i] = false;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, T;

	cin >> T;
	for (i = 0; i < T; i++) {
		init();
		solution();
		cout << answer << endl;
	}
	return 0;
}