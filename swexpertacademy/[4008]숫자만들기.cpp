#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000000
#define MIN -100000000

using namespace std;

int N, max_ans, min_ans;
int opnum[4];
char p[4] = { '+', '-', '*', '/' };
vector<int> num;
vector<char> op;

void init()
{
	num.clear();
	op.clear();
	max_ans = MIN;
	min_ans = MAX;
}

void cal()
{
	vector<int> tnum = num;
	vector<char> top = op;

	while(!top.empty()) {
		if (top[0] == '+')
			tnum[0] = tnum[0] + tnum[1];
		else if(top[0] == '-')
			tnum[0] = tnum[0] - tnum[1];
		else if (top[0] == '*')
			tnum[0] = tnum[0] * tnum[1];
		else 
			tnum[0] = tnum[0] / tnum[1];

		top.erase(top.begin());
		tnum.erase(tnum.begin() + 1);
	}

	max_ans = max(max_ans, tnum[0]);
	min_ans = min(min_ans, tnum[0]);
}

void DFS(int cnt)
{
	if (cnt == N - 1) {
		cal();
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (opnum[i] > 0) {
				--opnum[i];
				op.push_back(p[i]);
				DFS(cnt + 1);
				op.erase(op.end() - 1);
				++opnum[i];
			}
		}
	}
}

void solution()
{
	int i, j;

	cin >> N;
	for (i = 0; i < 4; i++)
		cin >> opnum[i];
	for (i = 0; i < N; i++) {
		cin >> j;
		num.push_back(j);
	}

	DFS(0);

	return;
}

int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++) {
		init();
		solution();
		cout << "#" << i << " " << max_ans - min_ans << endl;
	}
}
