#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int N, answer = 0;
int board[100][100];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<pair<int, int>> hole[5];
pair<int, int> endpos;
vector<pair<int, int>> start;

void init()
{
	int i;

	answer = 0;
	for (i = 0; i < 5; i++)
		hole[i].clear();
	start.clear();
	memset(board, 0, sizeof(int) * 100);
	for (i = 0; i < 100; i++)
		memset(board[i], 0, sizeof(int) * 100);
}

void game(int x, int y, int d)
{
	int i, j, cnt = 0, nd;
	int tx, ty, nx, ny;

	nd = d;
	tx = x + dir[nd][0];
	ty = y + dir[nd][1];
	while (true) {
		if ((tx == x && ty == y) || board[tx][ty] == -1) {
			//시작점으로 돌아오거나 블랙홀에 도착했을때
			answer = max(answer, cnt);
			return;
		}
		if (tx < 0 || ty < 0 || tx >= N || ty >= N) {
			//벽에 부딪혔을때
			answer = max(answer, cnt * 2 + 1);
			return;
		}

		if (board[tx][ty] == 1) {
			if (nd == 2) {
				++cnt;
				nd = 1;
			}
			else if (nd == 3) {
				++cnt;
				nd = 0;
			}
			else {
				answer = max(answer, cnt * 2 + 1);
				return;
			}
		}
		else if (board[tx][ty] == 2) {
			if (nd == 0) {
				++cnt;
				nd = 1;
			}
			else if (nd == 3) {
				++cnt;
				nd = 2;
			}
			else {
				answer = max(answer, cnt * 2 + 1);
				return;
			}
		}
		else if (board[tx][ty] == 3) {
			if (nd == 1) {
				++cnt;
				nd = 2;
			}
			else if (nd == 0) {
				++cnt;
				nd = 3;
			}
			else {
				answer = max(answer, cnt * 2 + 1);
				return;
			}
		}
		else if (board[tx][ty] == 4) {
			if (nd == 1) {
				++cnt;
				nd = 0;
			}
			else if (nd == 2) {
				++cnt;
				nd = 3;
			}
			else {
				answer = max(answer, cnt * 2 + 1);
				return;
			}
		}
		else if (board[tx][ty] == 5) {
			answer = max(answer, cnt * 2 + 1);
			return;
		}
		else if (6 <= board[tx][ty] && board[tx][ty] <= 10) {
			int index = board[tx][ty] - 6;
			if (hole[index][0].first == tx && hole[index][0].second == ty) {
				tx = hole[index][1].first;
				ty = hole[index][1].second;
			}
			else {
				tx = hole[index][0].first;
				ty = hole[index][0].second;
			}
		}
		tx += dir[nd][0];
		ty += dir[nd][1];
	}
}

void solution()
{
	int i, j;

	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> board[i][j];
			if (6 <= board[i][j] && board[i][j] <= 10)
				hole[board[i][j] - 6].push_back(make_pair(i, j));
			else if (board[i][j] == 0)
				start.push_back(make_pair(i, j));
		}
	}

	for (i = 0; i < start.size(); i++) {
		for (j = 0; j < 4; j++) {
			game(start[i].first, start[i].second, j);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, T;
	cin >> T;
	for (i = 1; i <= T; i++) {
		init();
		solution();
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}
