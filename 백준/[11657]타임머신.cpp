#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2100000000;

using namespace std;

typedef struct city {
	int from;
	int to;
	int d;

	city(int _f, int _t, int _d) : from(_f), to(_t), d(_d) {};
};
vector<city> edge;
long long dist[501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k, N, M;
	int a, b, c;

	cin >> N >> M;
	for (i = 1; i <= N; i++)
		dist[i] = INF;

	for (j = 0; j < M; j++) {
		cin >> a >> b >> c;
		edge.push_back(city(a, b, c));
	}

	dist[1] = 0;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < edge.size(); j++) {
			a = edge[j].from;
			b = edge[j].to;
			c = edge[j].d;

			if (dist[a] == 2100000000) continue;
			else if (dist[a] + c < dist[b])
				dist[b] = dist[a] + c;
		}
	}

	for (j = 0; j < edge.size(); j++) {
		a = edge[j].from;
		b = edge[j].to;
		c = edge[j].d;

		if (dist[a] == 2100000000) continue;
		else if (dist[a] + c < dist[b]) {
			cout << -1 << "\n";
			return 0;
		}
	}

	for (i = 2; i <= N; i++) {
		if (dist[i] == 2100000000)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}
