#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct block {
	int x;
	int y;
	int rainbow;
	int sz;

	block(int _x, int _y, int _r, int _s) : x(_x), y(_y), rainbow(_r), sz(_s) {};
}block;

bool compare(const block& a, const block& b)
{
	if (a.sz == b.sz) {
		if (a.rainbow == b.rainbow) {
			if (a.x == b.x) {
				return a.y > b.y;
			}
			else
				return a.x > b.x;
		}
		else
			return a.rainbow >  b.rainbow;
	}
	else
		return a.sz > b.sz;
}

vector<block> sortingvector;
vector<pair<int, int>> rainbowpoint;
queue<pair<int, int>> Q;
int dir[4][2] = { {-1 ,0}, {0, 1},{1, 0},{0, -1} };
bool visit[20][20];
int map[20][20];
int tempmap[20][20];
int N, M;

void BFS(int x, int y, int num)
{
	int i, sz = 1, rsz = 0;
	int tx, ty, nx, ny;


	Q.push(make_pair(x, y));
	visit[x][y] = true;
	while (!Q.empty()) {
		tx = Q.front().first;
		ty = Q.front().second;
		Q.pop();

		for (i = 0; i < 4; i++) {
			nx = tx + dir[i][0];
			ny = ty + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
				if (map[nx][ny] == num || map[nx][ny] == 0) {
					if (map[nx][ny] == 0) 
						++rsz;
					++sz;
					visit[nx][ny] = true;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	if (sz > 1) {
		sortingvector.push_back(block(x, y, rsz, sz));
		for (i = 0; i < rainbowpoint.size(); i++)
			visit[rainbowpoint[i].first][rainbowpoint[i].second] = false;
	}
}

void maperase(int x, int y, int num)
{
	int i, j, score = 1;
	int tx, ty, nx, ny;

	memset(visit, false, sizeof(bool) * N);
	for (i = 0; i < N; i++)
		memset(visit[i], false, sizeof(bool) * N);
	Q.push(make_pair(x, y));
	visit[x][y] = true;
	map[x][y] = 6;
	while (!Q.empty()) {
		tx = Q.front().first;
		ty = Q.front().second;
		Q.pop();

		for (i = 0; i < 4; i++) {
			nx = tx + dir[i][0];
			ny = ty + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
				if (map[nx][ny] == 0 || map[nx][ny] == num) {
					++score;
					visit[nx][ny] = true;
					map[nx][ny] = 6;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void gravity()
{
	int i, j, k;

	for (j = 0; j < N; j++) {
		for (i = N - 2; i >= 0; --i) {
			if (0 <= map[i][j] && map[i][j] < 6) {
				for (k = i + 1; k < N; k++) {
					if (map[k][j] != 6) {
						//중간에 다른 블럭을 만난경우
						break;
					}
				}
				//블록을 못만나고 끝까지 온경우
				if (k - 1 != i) {
					map[k - 1][j] = map[i][j];
					map[i][j] = 6;
				}
			}
		}
	}
}

void mapturn()
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			tempmap[i][j] = map[j][N - 1- i];
		}
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			map[i][j] = tempmap[i][j];
}

void print()
{
	int i, j;

	cout << "------------------\n";
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == 0)
				cout << "R" << " ";
			else if (map[i][j] == -1) {
				cout << "B ";
			}
			else if (map[i][j] == 6)
				cout << "  ";
			else
				cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------\n\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, answer = 0;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		//cout << "current score : " << answer << endl;
		//#1. init
		memset(visit, false, sizeof(bool) * N);
		for (i = 0; i < N; i++)
			memset(visit[i], false, sizeof(bool) * N);
		rainbowpoint.erase(rainbowpoint.begin(), rainbowpoint.end());
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (map[i][j] == 0)
					rainbowpoint.push_back(make_pair(i, j));
			}
		}

		//print();
		//#2. BFS
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (map[i][j] > 0 && map[i][j] < 6 && !visit[i][j]) {
					BFS(i, j, map[i][j]);
				}
			}
		}
		if (sortingvector.empty())
			break;

		//#3. sorting
		sort(sortingvector.begin(), sortingvector.end(), compare);
		answer += (sortingvector[0].sz * sortingvector[0].sz);
		maperase(sortingvector[0].x, sortingvector[0].y, map[sortingvector[0].x][sortingvector[0].y]);
		sortingvector.erase(sortingvector.begin(), sortingvector.end());
		//print();

		//#4. gravity-turn-gravity
		gravity();
		mapturn();
		gravity();
		//print();
	}

	cout << answer << endl;

	return 0;
}
