#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dist[201][201] = {0};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = 99999999;
        }
    }
    for (i = 0; i < fares.size(); i++) {
        dist[fares[i][0] - 1][fares[i][1] - 1] = fares[i][2];
        dist[fares[i][1] - 1][fares[i][0] - 1] = fares[i][2];
    }
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    answer = dist[s - 1][a - 1] + dist[s - 1][b - 1];
    for (i = 0; i < n; i++) {        
        answer = min(answer, dist[s-1][i] + dist[i][a-1] + dist[i][b-1]);
    }
    return answer;
}
