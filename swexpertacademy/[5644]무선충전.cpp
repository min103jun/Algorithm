#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int M, A;
pair<int, int> posA, posB, BC[8];
int moveA[101], moveB[101], dis[8], energy[8];
int dir[5][2] = { {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

void init()
{
	posA = make_pair(1, 1);
	posB = make_pair(10, 10);
}

int solution()
{
	int i, j, answer = 0;
	int tx, ty, nx, ny, e, d;
	vector<pair<int, int>> BCA, BCB;

	cin >> M >> A;
	moveA[0] = moveB[0] = 0;
	for (i = 1; i <= M; i++)
		cin >> moveA[i];
	for (i = 1; i <= M; i++)
		cin >> moveB[i];
	for (i = 0; i < A; i++) {
		cin >> ty >> tx >> d >> e;
		BC[i] = make_pair(tx, ty);
		dis[i] = d;
		energy[i] = e;
	}

	for (i = 0; i <= M; i++) {
		//A와 B의 이동
		posA.first += dir[moveA[i]][0];
		posA.second += dir[moveA[i]][1];
		posB.first += dir[moveB[i]][0];
		posB.second += dir[moveB[i]][1];

		//현재위치에서 A와 B가 갈수있는 모든 발전소 탐색하여 발전소 번호와 에너지크기를 넣음
		for (j = 0; j < A; j++) {
			d = abs(posA.first - BC[j].first) + abs(posA.second - BC[j].second);
			if (d <= dis[j])
				BCA.push_back(make_pair(j, energy[j]));
			d = abs(posB.first - BC[j].first) + abs(posB.second - BC[j].second);
			if (d <= dis[j])
				BCB.push_back(make_pair(j, energy[j]));
		}
		//에너지 크기에 따라 내림차순으로 정렬
		sort(BCA.begin(), BCA.end(), compare);
		sort(BCB.begin(), BCB.end(), compare);

		if (BCA.empty() && BCB.empty())
			continue;
		else if (BCA.empty() && !BCB.empty())
			answer += BCB[0].second;
		else if(!BCA.empty() && BCB.empty())
			answer += BCA[0].second;
		else if (BCA.size() == 1 && BCB.size() == 1) {
			//둘다 크기가 1일때;
			if (BCA[0].first == BCB[0].first)
				answer += BCA[0].second;//같은 구역이라면 나눠가져야한다.
			else
				answer += BCA[0].second + BCB[0].second;
		}
		else if (BCA.size() == 1 && BCB.size() > 1) {
			if (BCA[0].first == BCB[0].first) {
				answer += BCA[0].second + BCB[1].second;
			}
			else {
				answer += BCA[0].second + BCB[0].second;
			}
		}
		else if (BCA.size() > 1 && BCB.size() == 1) {
			if (BCA[0].first == BCB[0].first) {
				answer += BCA[1].second + BCB[0].second;
			}
			else {
				answer += BCA[0].second + BCB[0].second;
			}
		}
		else if (BCA.size() > 1 && BCB.size() > 1) {
			if (BCA[0].first == BCB[0].first) {
				if (BCA[0].second + BCB[1].second < BCA[1].second + BCB[0].second)
					answer += BCA[1].second + BCB[0].second;
				else
					answer += BCA[0].second + BCB[1].second;
			}
			else
				answer += BCA[0].second + BCB[0].second;
		}
		BCA.clear();
		BCB.clear();
	}
	return answer;
}

int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++) {
		init();
		cout << "#" << i << " " << solution() << "\n";
	}

	return 0;
}
