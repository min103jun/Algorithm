//해시를쓰는 이유. input이 10만, n^2 방식으로 일일이 탐색할 수 없다.!
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> M;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i;

    for (i = 0; i < participant.size(); i++) {
        if (M.find(participant[i]) == M.end())
            M[participant[i]] = 1;
        else
            M[participant[i]]++;
    }

    for (i = 0; i < completion.size(); i ++) {
        M[completion[i]]--;
    }

    for (map<string, int>::iterator iter = M.begin(); iter != M.end(); iter++) {
        if (iter->second != 0) {
            answer = iter->first;
            break;
        }
    }
    return answer;
}
