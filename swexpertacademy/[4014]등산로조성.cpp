#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int map[20][20];
bool visit[20][20];

int solution()
{
	int i, j, k, N, X, temp, answer = 0;
	bool flag;
	cin >> N >> X;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	memset(visit, false, sizeof(bool) * N);
	for (i = 0; i < N; i++)
		memset(visit[i], false, sizeof(bool) * N);
	for (i = 0; i < N; i++) {
		temp = map[i][0];
		flag = false;
		j = 1;
		while (j < N) {
			if (map[i][j] == temp) {
				++j;
			}
			else if (abs(temp - map[i][j]) > 1) {
				//높이가 2이상 차이나면 안된다.
				flag = true;
				break;
			}
			else if(map[i][j] < temp) {
				temp = map[i][j];
				if (j + X > N) {
					flag = true;
					break;
				}
				for (k = j; k < j + X; k++) {
					if (temp != map[i][k] || visit[i][k] == true) {
						flag = true;
						break;
					}
					else
						visit[i][k] = true;
				}

				if (flag) {
					break;
				}
				else {
					j = k;
				}
			}
			else if (temp < map[i][j]) {
				if (j - X < 0) {
					flag = true;
					break;
				}
				for (k = j - 1; k >= j - X; k--) {
					if (temp != map[i][k] || visit[i][k] == true) {
						flag = true;
						break;
					}
					else
						visit[i][k] = true;
				}

				if (flag)
					break;
				else {
					temp = map[i][j];
					++j;
				}
			}
		}

		if (!flag)
			++answer;
	}

	memset(visit, false, sizeof(bool) * N);
	for (i = 0; i < N; i++)
		memset(visit[i], false, sizeof(bool) * N);
	for (j = 0; j < N; j++) {
		temp = map[0][j];
		flag = false;
		i = 1;
		while (i < N) {
			if (map[i][j] == temp) {
				++i;
			}
			else if (abs(temp - map[i][j]) > 1) {
				//높이가 2이상 차이나면 안된다.
				flag = true;
				break;
			}
			else if (map[i][j] < temp) {
				temp = map[i][j];
				if (i + X > N) {
					flag = true;
					break;
				}
				for (k = i; k < i + X; k++) {
					if (temp != map[k][j] || visit[k][j] == true) {
						flag = true;
						break;
					}
					else
						visit[k][j] = true;
				}

				if (flag) {
					break;
				}
				else {
					i = k;
				}
			}
			else if (temp < map[i][j]) {
				if (i - X < 0) {
					flag = true;
					break;
				}
				for (k = i - 1; k >= i - X; k--) {
					if (temp != map[k][j] || visit[k][j] == true) {
						flag = true;
						break;
					}
					else
						visit[k][j] = true;
				}

				if (flag)
					break;
				else {
					temp = map[i][j];
					++i;
				}
			}
		}

		if (!flag)
			++answer;
	}
	return answer;
}
int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++) {
		cout << "#" << i << " " << solution() << endl;
	}
	return 0;
}
