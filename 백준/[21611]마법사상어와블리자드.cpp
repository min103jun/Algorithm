#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[49][49];
int answerset[4] = { 0,0,0,0 };
vector<int> bidsnum;

void drawmap(int N)
{
	int dir[4][2] = { {0, -1},{1, 0},{0, 1},{-1, 0} };
	int i, x, y, cnt = 1, dirnum = 0, idx = 1;

	x = y = N / 2;
	bidsnum.push_back(0);
	while (true) {
		for (i = 0; i < cnt; i++) {
			x += dir[dirnum][0];
			y += dir[dirnum][1];
			if(map[x][y] > 0)
				bidsnum.push_back(map[x][y]);
			map[x][y] = idx++;
			if (idx == N * N)
				return;
		}
		dirnum = (dirnum + 1) % 4;
		if (dirnum == 0 || dirnum == 2)
			++cnt;
	}
}

void blizard(int N, int d, int s)
{
	int dir[5][2] = { {0, 0},{-1, 0},{1, 0},{0, -1},{0, 1} };
	int i, x = N / 2, y = N / 2;
	vector<int> temp;

	for (i = 0; i < s; i++) {
		x += dir[d][0];
		y += dir[d][1];
		if (x >= 0 && y >= 0 && x < N && y < N && map[x][y] < bidsnum.size()) {
			temp.push_back(map[x][y]);
		}
		else
			break;
	}

	for (i = temp.size() - 1; i >= 0; i--) {
		bidsnum.erase(bidsnum.begin() + temp[i]);
	}
}

void chain(int N)
{
	bool flag;
	int i, j, cnt, temp;
	vector<pair<int, int>> temparr;

	while (bidsnum.size() > 1) {
		flag = false;
		temparr.clear();
		temp = bidsnum[1];
		cnt = 1;
		for (int i = 2; i < bidsnum.size(); i++) {
			if (bidsnum[i] == temp) {
				++cnt;
				if(i == bidsnum.size() - 1 && cnt >= 4)
					temparr.push_back(make_pair(i - cnt + 1, cnt));
			}
			else {
				if (cnt >= 4) {
					temparr.push_back(make_pair(i - cnt, cnt));
				}
				temp = bidsnum[i];
				cnt = 1;
			}
		}
		if (temparr.empty()) {
			return;
		}
		else {
			for (i = temparr.size() - 1; i >= 0; i--) {
				answerset[bidsnum[temparr[i].first]] += temparr[i].second;
				for (j = 0; j < temparr[i].second; j++) {
					bidsnum.erase(bidsnum.begin() + temparr[i].first);
				}
			}
		}
	}
}

vector<int> grouping(int N)
{
	vector<int> newarr;
	int i, temp, cnt;

	newarr.push_back(0);
	temp = bidsnum[1];
	cnt = 1;
	for (i = 2; i < bidsnum.size(); i++) {
		if (bidsnum[i] == temp) {
			++cnt;
		}
		else {
			newarr.push_back(cnt);
			newarr.push_back(temp);
			if (newarr.size() == N * N)
				return newarr;
			temp = bidsnum[i];
			cnt = 1;
		}
	}
	newarr.push_back(cnt);
	newarr.push_back(temp);
	return newarr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, N, M, d, s;
	int x, y;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	drawmap(N);

	for (i = 0; i < M; i++) {
		//step1. 블리자드 시전
		cin >> d >> s;
		blizard(N, d, s);
		//step2. 연속되는 4개이상의 블럭 폭발.
		if(bidsnum.size() > 1)
			chain(N);
		if(bidsnum.size() > 1)
			bidsnum = grouping(N);
	}

	cout << answerset[1] + (answerset[2] * 2) + (answerset[3] * 3) << "\n";
	return 0;
}
