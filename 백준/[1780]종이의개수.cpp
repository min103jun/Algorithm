#include <iostream>

using namespace std;

int N, map[2187][2187];
int answer[3] = {0, 0, 0};

void DFS(int x, int y, int sz)
{
	if (sz == 1) {
		++answer[map[x][y] + 1];
		return;
	}
	else {
		bool flag = true;
		for (int i = x; i < x + sz; i++) {
			for (int j = y; j < y + sz; j++) {
				if (map[i][j] != map[x][y]) {
					for (int k = 0; k < 3; k++) {
						for (int l = 0; l < 3; l++) {
							DFS(x + (sz / 3) * k, y + (sz / 3) * l, sz / 3);
						}
					}
					return;
				}
			}
		}
		++answer[map[x][y] + 1];
	}
}

int main()
{
	int i, j, temp;
	bool flag = false;
	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	DFS(0, 0, N);

	cout << answer[0] << "\n" << answer[1] << "\n" << answer[2] << "\n";

	return 0;
}
