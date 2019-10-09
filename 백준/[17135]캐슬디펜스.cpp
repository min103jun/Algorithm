#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;
int map[15][15];
vector<pair<int, int>> enemy;
vector<int> archor;
int N, M, D;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

void check()
{
	int i, j, distance, ans = 0;
	int min_value, idx, erase_idx, len;
	vector<int> arr;
	vector<pair<int, int>> Q;

	for (i = 0; i < enemy.size(); i++)
		Q.push_back(enemy[i]);

	while (!Q.empty()) {
		//1. 거리를 재고 없애는 것 부터.
		for (i = 0; i < archor.size(); i++) {
			min_value = 999;
			erase_idx = -1;
			for (j = 0; j < Q.size(); j++) {
				distance = abs(Q[j].first - N) + abs(Q[j].second - archor[i]);
				if (distance <= D && distance < min_value) {
					min_value = distance;
					erase_idx = j;
				}
			}
			if(erase_idx != -1)
				arr.push_back(erase_idx);
		}

		//없애야할 애들 없앰.
		sort(arr.begin(), arr.end(), greater<int>());
		arr.erase(unique(arr.begin(), arr.end()), arr.end());
		for (i = 0; i < arr.size(); i++) {
			Q.erase(Q.begin() + arr[i]);
			ans++;
		}
		arr.erase(arr.begin(), arr.end());

		//위치 줄임
		for (i = 0; i < Q.size();) {
			Q[i].first++;
			if (Q[i].first >= N) {
				//죽어야함
				Q.erase(Q.begin() + i);
			}
			else
				i++;
		}
	}

	if (answer < ans)
		answer = ans;
}

void DFS(int index, int cnt)
{
	if (cnt == 3) {
		check();
		return;
	}

	for (int i = index; i < M; i++) {
		archor.push_back(i);
		DFS(i + 1, cnt + 1);
		archor.erase(archor.end() - 1);
	}
}

void solution()
{
	int i, j;
	
	cin >> N >> M >> D;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				enemy.push_back(make_pair(i, j));
			}
		}
	}
	sort(enemy.begin(), enemy.end(), compare);

	for (i = 0; i < M; i++) {
		archor.push_back(i);
		DFS(i + 1, 1);
		archor.erase(archor.end() - 1);
	}
}

int main()
{
	solution();
	cout << answer << "\n";
	return 0;
}
