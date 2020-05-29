//문제를 읽어보면 MST라는 것을 파악할 수 있다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

typedef struct info {
    int from;
    int to;
    int d;

    info(int _f, int _t, int _d) : from(_f), to(_t), d(_d) {};
}info;

bool visit[300][300];
int landingmap[300][300];
int parent[90001];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<info> graph;
map<pair<int, int>, int> M;
queue<pair<int, int>> Q;

bool compare(const info& a, const info& b)
{
    return a.d < b.d;
}

int getparent(int n)
{
    if (parent[n] == n)
        return n;
    else
        return getparent(parent[n]);
}

void unionparent(int n, int m)
{
    int nn = getparent(n), nm = getparent(m);
    parent[nn] = nm;
}

int solution(vector<vector<int>> land, int height) {
    int i, j, k, sz, answer = 0, cnt = 1;
    int tx, ty, nx, ny;
    pair<int, int> key;
    bool flag;

    sz = land.size();
    memset(visit, false, sizeof(bool) * sz);
    for (i = 0; i < sz; i++)
        memset(visit[i], false, sizeof(bool) * sz);
    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz; j++) {
            if (visit[i][j] == false) {
                visit[i][j] = true;
                landingmap[i][j] = cnt;
                Q.push(make_pair(i, j));
                while (!Q.empty()) {
                    tx = Q.front().first;
                    ty = Q.front().second;
                    Q.pop();
                    for (k = 0; k < 4; k++) {
                        nx = tx + dir[k][0];
                        ny = ty + dir[k][1];
                        if (nx >= 0 && ny >= 0 && nx < sz && ny < sz && !visit[nx][ny] && abs(land[nx][ny] - land[tx][ty]) <= height) {
                            visit[nx][ny] = true;
                            landingmap[nx][ny] = cnt;
                            Q.push(make_pair(nx, ny));
                        }
                    }
                }
                ++cnt;
            }
        }
    }

    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz; j++) {
            if (i + 1 < sz && landingmap[i][j] != landingmap[i + 1][j]) {
                key = make_pair(landingmap[i][j], landingmap[i + 1][j]);
                if (M.find(key) == M.end())
                    M[key] = abs(land[i + 1][j] - land[i][j]);
                else
                    M[key] = min(M[key], abs(land[i + 1][j] - land[i][j]));
            }
            if (j + 1 < sz && landingmap[i][j] != landingmap[i][j + 1]) {
                key = make_pair(landingmap[i][j], landingmap[i][j + 1]);
                if (M.find(key) == M.end())
                    M[key] = abs(land[i][j + 1] - land[i][j]);
                else
                    M[key] = min(M[key], abs(land[i][j + 1] - land[i][j]));
            }
        }
    }

    for (map<pair<int, int>, int>::iterator iter = M.begin(); iter != M.end(); ++iter) 
        graph.push_back(info(iter->first.first, iter->first.second, iter->second));
    sort(graph.begin(), graph.end(), compare);
    for (i = 1; i <= cnt; i++)
        parent[i] = i;

    for (i = 0; i < graph.size(); i++) {
        if (getparent(graph[i].from) != getparent(graph[i].to)) {
            answer += graph[i].d;
            unionparent(graph[i].from, graph[i].to);
        }
    }
    return answer;
}

int main()
{
    solution({ {1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}}, 3);
    return 0;
}
