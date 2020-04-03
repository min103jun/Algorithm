//1, 0 두 개를 바꾸는 연산은 비트연산이 빠르다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    string str = "0", res;
    int i, j, idx;

    answer.push_back(0);
    for (i = 1; i < n; i++) {
        idx = answer.size();
        answer.push_back(0);
        for (j = idx - 1; j >= 0; j--) {
            answer.push_back(!answer[j]);
        }
    }
    return answer;
}
