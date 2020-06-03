#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef struct info {
	int x;
	int y;
	int d;
	info(int _x, int _y, int _d) {
		x = _x;
		y = _y;
		d = _d;
	}
}info;

int N, M, parent[200000];
vector<info> graph;

bool compare(const info& a, const info& b)
{
	return a.d < b.d;
}

int findparent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = findparent(parent[x]);
}

void unionparent(int x, int y)
{
	int nx = findparent(x), ny = findparent(y);
	parent[nx] = ny;
}

int solution()
{
	int i, j, answer =0;
	int x, y, d;

	//init
	for (i = 0; i < N; i++)
		parent[i] = i;
	graph.erase(graph.begin(), graph.end());
	for (i = 0; i < M; i++) {
		cin >> x >> y >> d;
		graph.push_back(info(x, y, d));
		answer += d;
	}
	sort(graph.begin(), graph.end(), compare);

	for (i = 0; i < M; i++) {
		if (findparent(graph[i].x) != findparent(graph[i].y)) {
			answer -= graph[i].d;
			unionparent(graph[i].x, graph[i].y);
		}
	}

	return answer;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		cout << solution() << endl;
	}

	return 0;
}
