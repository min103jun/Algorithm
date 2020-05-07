#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> M;

long long find(int num)
{
    if (!M[num]) 
        return num;
    return M[num] = find(M[num]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    int i, sz;
    long long tmp;

    sz = room_number.size();
    for (i = 0; i < sz; i++) {
        if (!M[room_number[i]]) {
            answer.push_back(room_number[i]);
            M[room_number[i]] = find(room_number[i] + 1);
        }
        else {
            tmp = find(room_number[i]);
            answer.push_back(tmp);
            M[tmp] = find(tmp + 1);
        }
    }
    return answer;
}
