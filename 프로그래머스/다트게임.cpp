#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int i, index, answer = 0, cnt = 0;
    int score[3] = { 0, 0, 0 };

    index = 0;
    for (i = 0; i < 3; i++) {
        if ('0' <= dartResult[index] && dartResult[index] <= '9') {
            if (dartResult[index + 1] == '0') {
                score[i] = 10;
                index += 2;
            }
            else {
                score[i] = dartResult[index] - '0';
                ++index;
            }
        }

        if (dartResult[index] == 'S')
            score[i] = pow(score[i], 1);
        else if (dartResult[index] == 'D')
            score[i] = pow(score[i], 2);
        else
            score[i] = pow(score[i], 3);
        ++index;

        if (dartResult[index] == '*') {
            score[i] *= 2;
            if (i != 0)
                score[i - 1] *= 2;
            ++index;
        }
        else if (dartResult[index] == '#') {
            score[i] *= (-1);
            ++index;
        }
    }

    return score[0] + score[1] + score[2];
}
