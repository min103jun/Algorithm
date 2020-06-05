#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[10][10];
int sz, N, h1 = 0, h2 = 0, answer = 99999999;
vector<pair<int, int>> people;
bool visit[10];
pair<int, int> s1, s2;

void init()
{
	h1 = 0; h2 = 0;
	people.clear();
	answer = 99999999;
}

void check()
{
	int i, time1, time2, cnt = 0, stsz;
	vector<int> wait1, wait2;
	queue<int> stair1, stair2;

	for (i = 0; i < sz; i++) {
		if (visit[i] == true) {
			wait1.push_back(abs(people[i].first - s1.first) + abs(people[i].second - s1.second) + 1);
		}
		else {
			wait2.push_back(abs(people[i].first - s2.first) + abs(people[i].second - s2.second) + 1);
		}
	}
	sort(wait1.begin(), wait1.end());
	sort(wait2.begin(), wait2.end());

	time1 = 1;
	while (cnt < sz) {
		if (!stair1.empty()) {
			stsz = stair1.size();
			for (i = 0; i < stsz; i++) {
				if (stair1.front() <= time1) {
					stair1.pop();
					++cnt;
				}
				else
					break;
			}
		}
		if (!stair2.empty()) {
			stsz = stair2.size();
			for (i = 0; i < stsz; i++) {
				if (stair2.front() <= time1) {
					stair2.pop();
					++cnt;
				}
				else
					break;
			}
		}

		if (!wait1.empty()) {
			stsz = wait1.size();
			for (i = 0; i < stsz; i++) {
				if (wait1[0] <= time1 && stair1.size() < 3) {
					stair1.push(time1 + h1);
					wait1.erase(wait1.begin());
				}
				else
					break;
			}
		}
		if (!wait2.empty()) {
			stsz = wait2.size();
			for (i = 0; i < stsz; i++) {
				if (wait2[0] <= time1 && stair2.size() < 3) {
					stair2.push(time1 + h2);
					wait2.erase(wait2.begin());
				}
				else
					break;
			}
		}
		++time1;
	}


	answer = min(answer, time1 - 1);
}

void DFS(int index)
{
	check();
	if (index == sz)
		return;
	for (int i = index; i < sz; i++) {
		visit[i] = true;
		DFS(i + 1);
		visit[i] = false;
	}
}

void solution()
{
	int i, j;
	queue<int> stair1, stair2;

	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) 
				people.push_back(make_pair(i, j));
			if (map[i][j] > 1) {
				if (h1 == 0) {
					h1 = map[i][j];
					s1 = make_pair(i, j);
				}
				else {
					h2 = map[i][j];
					s2 = make_pair(i, j);
				}
			}
		}
	}
	sz = people.size();
	memset(visit, false, sizeof(bool) * sz);
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
		cout << "#" << i << " " << answer << endl;
	}

	return 0;
}
