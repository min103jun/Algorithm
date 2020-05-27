#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct graphinfo {
	int from;
	int to;
	int d;

	graphinfo(int _f, int _t, int _d) : from(_f), to(_t), d(_d) {};
}graphinfo;

int E, V;
int parent[10001];
vector<graphinfo> info;

bool compare(const graphinfo& a, const graphinfo &b)
{
	return a.d < b.d;
}

int getparent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return getparent(parent[x]);
}

void unionparent(int x, int y)
{
	int nx = getparent(x), ny = getparent(y);
	parent[nx] = ny;
}

int main()
{
	int i, j, from, to, d, answer = 0;

	cin >> E >> V;
	//init
	for (i = 1; i <= E; i++) 
		parent[i] = i;

	//정보를 vector에 담는다. -> distance순으로 정렬하기 위해서
	for (i = 0; i < V; i++) {
		cin >> from >> to >> d;
		info.push_back(graphinfo(from, to, d));
	}
	sort(info.begin(), info.end(), compare);
	
	//union forest set을 이용하여 MST를 생성한다.
	for (i = 0; i < V; i++) {
		from = info[i].from;
		to = info[i].to;
		d = info[i].d;
		if (getparent(from) != getparent(to)) {
			//from과 to의 부모가 같다면 이미 연결되어있는것. 
			answer += d;
			unionparent(from, to);
		}
	}

	cout << answer << endl;
	return 0;
}
