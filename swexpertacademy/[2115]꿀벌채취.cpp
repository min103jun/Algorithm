#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

int cnt = 0, map[10][10];
int N, M, C, answer = 0;
int ans1 = 0, ans2 = 0;

void init()
{
	answer = 0;
}

void calMAX1(vector<int> vec, int index, int sum, int ans)
{
	ans1 = max(ans, ans1);
	if (index == vec.size())
		return;

	for (int i = index; i < vec.size(); i++) {
		if (sum + vec[i] > C)
			continue;
		calMAX1(vec, i + 1, sum + vec[i], ans + vec[i] * vec[i]);
	}
}

void calMAX2(vector<int> vec, int index, int sum, int ans)
{
	ans2 = max(ans, ans2);
	if (index == vec.size())
		return;

	for (int i = index; i < vec.size(); i++) {
		if (sum + vec[i] > C)
			continue;
		calMAX2(vec, i + 1, sum + vec[i], ans + vec[i] * vec[i]);
	}
}

void calC(int row1, int col1, int row2, int col2)
{
	int i;
	vector<int> A, B;

	ans1 = ans2 = 0;
	for (i = 0; i < M; i++) {
		A.push_back(map[row1][col1 + i]);
		B.push_back(map[row2][col2 + i]);
	}

	calMAX1(A, 0, 0, 0);
	calMAX2(B, 0, 0, 0);

	answer = max(answer, ans1 + ans2);
}

void calB(int row, int col)
{
	for (int i = row; i < N; i++) {
		int j;
		if (i == row)
			j = col + M;
		else
			j = 0;
		for (; j < N - M + 1; j++) {
			calC(row, col, i, j);
		}
	}
}

void solution()
{
	int i, j;

	cin >> N >> M >> C;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N - M + 1; j++) {
			calB(i, j);
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
