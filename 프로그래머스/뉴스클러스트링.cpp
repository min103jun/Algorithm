#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
//set_intersection을 하려면 1. 컨테이너가 벡터일 것, 2. 두 벡터가 정렬되어 있을 것, 3. 담을 벡터의 사이즈가 정해져 있어야 한다.
    int i, j, answer = 0, sz1, sz2, intersection, sum;
    vector<string> S1, S2, S3; //1.조건 컨테이너를 벡터로 잡음
    string tmp;

    sz1 = str1.size() - 1;
    for (i = 0; i < sz1; i++) {
        tmp = str1.substr(i, 2);
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        if ('a' <= tmp[0] && tmp[0] <= 'z' && 'a' <= tmp[1] && tmp[1] <= 'z') {
            S1.push_back(tmp);
        }
    }
    sz2 = str2.size() - 1;
    for (i = 0; i < sz2; i++) {
        tmp = str2.substr(i, 2);
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        if ('a' <= tmp[0] && tmp[0] <= 'z' && 'a' <= tmp[1] && tmp[1] <= 'z') {
            S2.push_back(tmp);
        }
    }

    sz1 = S1.size();
    sz2 = S2.size();
    sort(S1.begin(), S1.end()); 
    sort(S2.begin(), S2.end()); //조건2. 두개의 벡터를 정렬해야함
    S3.resize(S1.size() + S2.size());//조건3. 담을 벡터의 사이즈를 정해야 함
    vector<string>::iterator it = set_intersection(S1.begin(), S1.end(), S2.begin(), S2.end(), S3.begin());
    S3.erase(it, S3.end()); //미리 정해둔 사이즈. set_intersection의 반환값은 dset 벡터의 마지막 위치이다.
    intersection = S3.size();
    sum = sz1 + sz2 - intersection;
    if (sum == 0)
        return 65536;
    else
        return intersection * 65536 / sum;
}
