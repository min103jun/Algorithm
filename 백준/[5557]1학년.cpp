#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int num[100];
long long check[100][21];
bool visit[100][21];

int main()
{
	int i, j, k, N;

	cin >> N;
	memset(check, 0, sizeof(long long) * N);
	memset(visit, false, sizeof(bool) * N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		memset(check[i], 0, sizeof(long long) * 21);
		memset(visit[i], false, sizeof(bool) * 21);
	}

	check[0][num[0]]++;
	visit[0][num[0]] = true;
	for (i = 1; i < N - 1; i++) {
		for (j = 0; j <= 20; j++) {
			if (visit[i - 1][j] == true) {
				if (j + num[i] <= 20) {
					check[i][j + num[i]] += check[i - 1][j];
					visit[i][j + num[i]] = true;
				}
				if (j - num[i] >= 0) {
					check[i][j - num[i]] += check[i - 1][j];
					visit[i][j - num[i]] = true;
				}
			}
		}
	}

	cout << check[N - 2][num[N - 1]] << endl;
	return 0;
}
