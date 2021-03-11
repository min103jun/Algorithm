#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
bool m[64][64] = { false };

void DFS(int x, int y, int sz)
{
	int i, j, n;
	bool temp, check = false;

	if (sz == 1) {
		if (!m[x][y]) cout << 0;
		else cout << 1;
		return;
	}
	temp = m[x][y];
	for (i = x; i < x + sz; i++) {
		for (j = y; j < y + sz; j++) {
			if (temp != m[i][j]) {
				check = true;
				break;
			}
		}
		if (check)
			break;
	}

	if (!check) {
		if (!temp) cout << 0;
		else cout << 1;
	}
	else {
		cout << "(";
		DFS(x, y, sz / 2);
		DFS(x, y + sz / 2, sz / 2);
		DFS(x + sz / 2, y, sz / 2);
		DFS(x + sz / 2, y + sz / 2, sz / 2);
		cout << ")";
	}
}

int main()
{
	int i, j;
	string str;
	bool check = false;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> str;
		for (j = 0; j < str.size(); j++) {
			if (str[j] == '1')
				m[i][j] = true;

			if (m[i][j] != m[0][0])
				check = true;
		}
	}

	if (!check) {
		if (!m[0][0]) cout << 0;
		else cout << 1;
	}
	else {
		cout << "(";
		DFS(0, 0, N / 2);
		DFS(0, N / 2, N / 2);
		DFS(N / 2, 0, N / 2);
		DFS(N / 2, N / 2, N / 2);
		cout << ")";
	}
	return 0;
}
