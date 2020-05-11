#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[10][10], papercnt[5] = {0, 0, 0, 0, 0};
int answer = 9999;
bool visit[10][10];
vector<pair<int, int>> pos;

void DFS(int index, int paper, int sum)
{
	if (paper == 0) {
		answer = min(answer, sum);
		return;
	}
	else if (visit[pos[index].first][pos[index].second] == true) {
		DFS(index + 1, paper, sum);
	}
	else {
		int x = pos[index].first, y = pos[index].second, nx, ny, i, j, k;
		bool flag;

		for (k = 5; k > 0; k--) {
			//5칸부터 가능한지 판단
			if (papercnt[k] >= 5)
				continue;
			flag = false;
			for (i = 0; i < k; i++) {
				for (j = 0; j < k; j++) {
					nx = x + i; ny = y + j;
					if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10 || map[nx][ny] == 0 || visit[nx][ny] == true) {
						flag = true;
						break;
					}
				}
				if (flag == true)
					break;
			}

			if (flag == false) {
				for (i = 0; i < k; i++) {
					for (j = 0; j < k; j++) {
						visit[x + i][y + j] = true;
						--paper;
					}
				}
				papercnt[k]++;
				DFS(index + 1, paper, sum + 1);
				papercnt[k]--;
				for (i = 0; i < k; i++) {
					for (j = 0; j < k; j++) {
						visit[x + i][y + j] = false;
						++paper;
					}
				}
			}
		}
	}
}

int main()
{
	int i, j, paper = 0;

	memset(visit, false, sizeof(bool) * 10);
	for (i = 0; i < 10; i++) {
		memset(visit[i], false, sizeof(bool) * 10);
		for (j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				pos.push_back(make_pair(i, j));
				++paper;
			}
		}
	}

	DFS(0, paper, 0);
	if (answer == 9999)
		cout << -1 << endl;
	else
		cout << answer << endl;

	return 0;
}
