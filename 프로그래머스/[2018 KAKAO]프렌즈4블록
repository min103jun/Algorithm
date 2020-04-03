//board를 아래로 내리는 동작을 큐를 이용한 반복문으로 해결
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int i, j, answer = 0, idx;
    int top[30], down[30];
    bool visit[30][30], flag;
    queue<char> Q;

    while (1) {
        flag = false;
        memset(visit, false, sizeof(bool) * m);
        for (i = 0; i < m; i++)
            memset(visit[i], false, sizeof(bool) * n);

        for (i = 0; i < m - 1; i++) {
            for (j = 0; j < n - 1; j++) {
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1] && board[i][j] != '0') {
                    visit[i][j] = visit[i][j + 1] = visit[i + 1][j] = visit[i + 1][j + 1] = true;
                    flag = true;
                }
            }
        }
        if (flag == false)
            break;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (visit[i][j] == true) {
                    board[i][j] = '0';
                    ++answer;
                }
            }
        }

        for (i = 0; i < n; i++) {
            for(j = m - 1; j >= 0; j--) {
                if (board[j][i] != '0') {
                    Q.push(board[j][i]);
                    board[j][i] = '0';
                }
            }
            idx = m - 1;
            while (!Q.empty()) {
                board[idx][i] = Q.front();
                Q.pop();
                --idx;
            }
        }
    }
    return answer;
}
