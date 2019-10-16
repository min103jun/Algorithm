#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N, answer = 99999;
int score[10];
bool team[10];
vector<int> graph[10];

void check()
{
	int i, j, start, cnt1 = 1, cnt2 = 1, check1 = 0, check2 = 0;
	int sum1 = 0, sum2 = 0, num;
	bool visit[10];
	stack<int> S;

	for (i = 0; i < N; i++) {
		visit[i] = false;
		if (team[i] == true)
			++check1;
		else
			++check2;
	}

	//구역1
	for (i = 0; i < N; i++) {
		if (team[i] == true) {
			start = i;
			break;
		}
	}
	S.push(start);
	visit[start] = true;
	while (!S.empty()) {
		start = S.top();
		S.pop();
		for (i = 0; i < graph[start].size(); i++) {
			if (visit[graph[start][i]] == false && team[graph[start][i]] == true) {
				S.push(graph[start][i]);
				visit[graph[start][i]] = true;
				++cnt1;
			}
		}
	}
	if (check1 != cnt1)
		return;
	//구역2
	for (i = 0; i < N; i++) {
		if (team[i] == false) {
			start = i;
			break;
		}
	}
	S.push(start);
	visit[start] = true;
	while (!S.empty()) {
		start = S.top();
		S.pop();
		for (i = 0; i < graph[start].size(); i++) {
			if (visit[graph[start][i]] == false && team[graph[start][i]] == false) {
				S.push(graph[start][i]);
				visit[graph[start][i]] = true;
				++cnt2;
			}
		}
	}
	if (check2 != cnt2)
		return;

	for (i = 0; i < N; i++) {
		if (team[i] == true)
			sum1 += score[i];
		else
			sum2 += score[i];
	}
	num = abs(sum1 - sum2);
	if (num < answer)
		answer = num;
}

void DFS(int index)
{
	check();

	if (index == N)
		return;

	for (int i = index; i < N; i++) {
		team[i] = true;
		DFS(i + 1);
		team[i] = false;
	}
}

void solution()
{
	int i, j, num, temp;
	
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> score[i];
		team[i] = false;
	}
	for (i = 0; i < N; i++) {
		cin >> num;
		for (j = 0; j < num; j++) {
			cin >> temp;
			graph[i].push_back(temp - 1);
		}
	}

	for (i = 0; i < N; i++) {
		team[i] = true;
		DFS(i + 1);
		team[i] = true;
	}
}

int main()
{
	solution();
	if (answer == 99999)
		cout << -1 << "\n";
	else
		cout << answer << "\n";

	return 0;
}
