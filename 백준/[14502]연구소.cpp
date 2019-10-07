#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int answer = 0, N, M;
int map[8][8];
vector<pair<int, int>> virus;
vector<pair<int, int>> possible;

void check()
{
	int ans = 0;
	int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	queue<pair<int, int>> Q;
	pair<int, int> temp;
	//int t_map[8][8];
	bool visited[8][8];
	int i, j, tempx, tempy;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == 0)
				visited[i][j] = true;
			else
				visited[i][j] = false;
			//t_map[i][j] = map[i][j];
		}
	}

	for (i = 0; i < virus.size(); i++) 
		Q.push(virus[i]);
	
	while (!Q.empty()) {
		temp = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++) {
			tempx = temp.first + dir[i][0];
			tempy = temp.second + dir[i][1];
			if (tempx < 0 || tempy < 0 || tempx >= N || tempy >= M)
				continue;
			if (visited[tempx][tempy] == false)
				continue;
			Q.push(make_pair(tempx, tempy));
			//t_map[tempx][tempy] = 2;
			visited[tempx][tempy] = false;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			//if (t_map[i][j] == 0)
			if(visited[i][j] == true)
				ans++;
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

	for (int i = index; i < possible.size(); i++) {
		map[possible[i].first][possible[i].second] = 1;
		DFS(i + 1, cnt + 1);
		map[possible[i].first][possible[i].second] = 0;
	}
}

void solution()
{
	int i, j;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
			else if (map[i][j] == 0)
				possible.push_back(make_pair(i, j));
		}
	}

	for (i = 0; i < possible.size(); i++) {
		map[possible[i].first][possible[i].second] = 1;
		DFS(i + 1, 1);
		map[possible[i].first][possible[i].second] = 0;
	}
}

int main()
{
	solution();
	cout << answer << "\n";
	system("pause");
	return 0 ;
}
