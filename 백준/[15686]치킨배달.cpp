#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N, M, answer = 99999;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<int> use;

void check()
{
	int i, j, distance, minvalue, sum = 0;

	for(i = 0; i < home.size(); i++){
		minvalue = 99999;
		for (j = 0; j < use.size(); j++) {
			distance = abs(home[i].first - chicken[use[j]].first) + abs(home[i].second - chicken[use[j]].second);
			if (distance < minvalue)
				minvalue = distance;
		}
		sum += minvalue;
	}

	if (sum < answer)
		answer = sum;
}

void DFS(int index, int cnt)
{
	if (cnt == M) {
		check();
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		use.push_back(i);
		DFS(i + 1, cnt + 1);
		use.erase(use.end() - 1);
	}
}

void solution()
{
	int i, j, temp;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 1)
				home.push_back(make_pair(i, j));
			else if (temp == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	for (i = 0; i < chicken.size(); i++) {
		use.push_back(i);
		DFS(i + 1, 1);
		use.erase(use.end() - 1);
	}
}

int main()
{
	solution();
	cout << answer << "\n";
	return 0;
}
