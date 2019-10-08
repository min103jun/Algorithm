#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct cctv {
	int num;
	int x;
	int y;
	int ds;
	int d[4];
}cctv;

int N, M, answer = 99999;
int map[8][8];
vector<cctv> arr;

void init()
{
	N = M = 0;
	answer = 99999;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			map[i][j] = 0;
	arr.erase(arr.begin(), arr.end());
}
void check()
{
	int i, j, k, d, ans = 0;
	int nx, ny;
	int dir[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };
	bool visited[8][8];

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 6)
				visited[i][j] = false;
			else
				visited[i][j] = true;
		}
	}
	for (i = 0; i < arr.size(); i++) {
		visited[arr[i].x][arr[i].y] = false;
		for (j = 0; j < arr[i].ds; j++) {
			d = arr[i].d[j];
			nx = arr[i].x;
			ny = arr[i].y;
			while (true) {
				nx += dir[d][0];
				ny += dir[d][1];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 6)
					break;
				visited[nx][ny] = false;
			}
		}
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (visited[i][j] == true)
				ans++;
	if (ans == 0) {
		cout << "0" << "\n";
		exit(0);
	}
	if (ans < answer)
		answer = ans;
}

void DFS(int index)
{
	if (index == arr.size()) {
		check();
		return;
	}

	for (int i = index; i < arr.size(); i++) {
		if (arr[i].num == 1) {
			arr[i].d[0] = 0;
			DFS(i + 1);
			arr[i].d[0] = 1;
			DFS(i + 1);
			arr[i].d[0] = 2;
			DFS(i + 1);
			arr[i].d[0] = 3;
			DFS(i + 1);
		}
		else if (arr[i].num == 2) {
			arr[i].d[0] = 0;
			arr[i].d[1] = 2;
			DFS(i + 1);
			arr[i].d[0] = 1;
			arr[i].d[1] = 3;
			DFS(i + 1);
		}
		else if (arr[i].num == 3) {
			arr[i].d[0] = 0;
			arr[i].d[1] = 1;
			DFS(i + 1);
			arr[i].d[0] = 1;
			arr[i].d[1] = 2;
			DFS(i + 1);
			arr[i].d[0] = 2;
			arr[i].d[1] = 3;
			DFS(i + 1);
			arr[i].d[0] = 3;
			arr[i].d[1] = 0;
			DFS(i + 1);
		}
		else if (arr[i].num == 4) {
			arr[i].d[0] = 0;
			arr[i].d[1] = 1;
			arr[i].d[2] = 2;
			DFS(i + 1);
			arr[i].d[0] = 1;
			arr[i].d[1] = 2;
			arr[i].d[2] = 3;
			DFS(i + 1);
			arr[i].d[0] = 2;
			arr[i].d[1] = 3;
			arr[i].d[2] = 0;
			DFS(i + 1);
			arr[i].d[0] = 3;
			arr[i].d[1] = 0;
			arr[i].d[2] = 1;
			DFS(i + 1);
		}
		else if (arr[i].num == 5) {
			arr[i].d[0] = 0;
			arr[i].d[1] = 1;
			arr[i].d[2] = 2;
			arr[i].d[3] = 3;
			DFS(i + 1);
		}
	}
}

void solution()
{
	int i, j, blank = 0;
	cctv in_cctv;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5) {
				in_cctv.num = map[i][j];
				in_cctv.x = i;
				in_cctv.y = j;
				if (map[i][j] == 1) {
					in_cctv.ds = 1;
				}
				else if (map[i][j] == 2) {
					in_cctv.ds = 2;
				}
				else if (map[i][j] == 3) {
					in_cctv.ds = 2;
				}
				else if (map[i][j] == 4) {
					in_cctv.ds = 3;
				}
				else if (map[i][j] == 5) {
					in_cctv.ds = 4;
				}
				arr.push_back(in_cctv);
			}
			else if (map[i][j] == 0)
				blank++;
		}
	}

	if (arr.size() == 0) {
		answer = blank;
		return;
	}
	if(arr.size())
	for (i = 0; i < arr.size(); i++) {
		if (arr[i].num == 1) {
			arr[i].d[0] = 0;
			DFS(i + 1);
			arr[i].d[0] = 1;
			DFS(i + 1);
			arr[i].d[0] = 2;
			DFS(i + 1);
			arr[i].d[0] = 3;
			DFS(i + 1);
		}
		else if (arr[i].num == 2) {
			arr[i].d[0] = 0;
			arr[i].d[1] = 2;
			DFS(i + 1);
			arr[i].d[0] = 1;
			arr[i].d[1] = 3;
			DFS(i + 1);
		}
		else if (arr[i].num == 3) {
			arr[i].d[0] = 0;
			arr[i].d[1] = 1;
			DFS(i + 1);
			arr[i].d[0] = 1;
			arr[i].d[1] = 2;
			DFS(i + 1);
			arr[i].d[0] = 2;
			arr[i].d[1] = 3;
			DFS(i + 1);
			arr[i].d[0] = 3;
			arr[i].d[1] = 0;
			DFS(i + 1);
		}
		else if (arr[i].num == 4) {
			arr[i].d[0] = 0;
			arr[i].d[1] = 1;
			arr[i].d[2] = 2;
			DFS(i + 1);
			arr[i].d[0] = 1;
			arr[i].d[1] = 2;
			arr[i].d[2] = 3;
			DFS(i + 1);
			arr[i].d[0] = 2;
			arr[i].d[1] = 3;
			arr[i].d[2] = 0;
			DFS(i + 1);
			arr[i].d[0] = 3;
			arr[i].d[1] = 0;
			arr[i].d[2] = 1;
			DFS(i + 1);
		}
		else if (arr[i].num == 5) {
			arr[i].d[0] = 0;
			arr[i].d[1] = 1;
			arr[i].d[2] = 2;
			arr[i].d[3] = 3;
			DFS(i + 1);
		}
	}
}

int main()
{
	while (1) {
		init();
		solution();
		cout << answer << endl;
	}

	return 0;
}
