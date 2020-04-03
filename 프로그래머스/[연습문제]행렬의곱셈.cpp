//2차원 vector의 동적할당 ==> resize(row, vector<type>(col, init_value));
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int i, j, k;

    answer.resize(arr1.size(), vector<int>(arr2[0].size(), 0));
    for (i = 0; i < arr1.size(); i++) {
        for (j = 0; j < arr2[0].size(); j++) {
            int sum = 0;
            for (k = 0; k < arr1[0].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }
    return answer;
}
