#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 9999

using namespace std;

int D, W, K, answer = MAX;
int map[13][20];
int check[13];

void init()
{
	answer = MAX;
	memset(check, 0, sizeof(int) * 13);
}

void cal(int change)
{
	int i, j, temp, cnt, max_cnt;
	int cmap[13][20];
	bool flag = false;
	for (i = 0; i < D; i++) {
		if (check[i] == 0)
			for (j = 0; j < W; j++)
				cmap[i][j] = map[i][j];
		else if (check[i] == 1)
			for (j = 0; j < W; j++)
				cmap[i][j] = 0;
		else
			for (j = 0; j < W; j++)
				cmap[i][j] = 1;
	}

	for (j = 0; j < W; j++) {
		cnt = 1;
		flag = false;
		temp = cmap[0][j];
		for (i = 1; i < D; i++) {
			if (cmap[i][j] == temp) {
				++cnt;
				if (cnt >= K) {
					flag = true;
					break;
				}
			}
			else {
				cnt = 1;
				temp = cmap[i][j];
			}
		}
		if (!flag)
			return;
	}
	answer = min(answer, change);
}

void DFS(int index, int cnt, int change)
{
	if (cnt == D) {
		if(change < answer)
			cal(change);
		return;
	}
	else {
		DFS(index + 1, cnt + 1, change);
		check[index] = 1;
		DFS(index + 1, cnt + 1, change + 1);
		check[index] = 2;
		DFS(index + 1, cnt + 1, change + 1);
		check[index] = 0;
	}
}

void solution()
{
	int i, j;

	cin >> D >> W >> K;
	for (i = 0; i < D; i++)
		for (j = 0; j < W; j++)
			cin >> map[i][j];

	if (K == 1) {
		answer = 0;
		return;
	}

	DFS(1, 1, 0);
	check[0] = 1;
	DFS(1, 1, 1);
	check[0] = 2;
	DFS(1, 1, 1);
	check[0] = 0;

	return;
}

int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++) {
		init();
		solution();
		cout << "#" << i << " " << answer << endl;
	}
	return 0;
}
