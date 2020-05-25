#include <vector>
#include <algorithm>
#include <queue>
#define MAX 99999999
using namespace std;

vector<pair<int, int>> graph[51];
queue<pair<int, int>> Q;
int D[50];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0, sz;
    int here, next, d, nextd;
    int i, j;

    for (int i = 0; i <= N; i++)
        D[i] = MAX;
    sz = road.size();
    for (i = 0; i < sz; i++) {
        graph[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        graph[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    
    Q.push(make_pair(1, 0));
    D[1] = 0;
    while (!Q.empty()) {
        here = Q.front().first;
        d = Q.front().second;
        Q.pop();
        for (i = 0; i < graph[here].size(); i++) {
            next = graph[here][i].first;
            nextd = graph[here][i].second + d;
            if (nextd < D[next]) {
                D[next] = nextd;
                Q.push(make_pair(next, nextd));
            }
        }
    }

    for (i = 1; i <= N; i++) {
        if (D[i] <= K)
            ++answer;
    }
    return answer;
}
