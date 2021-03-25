#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, vector<int>> database;
set<string> possiblekey;

vector<string> strcat(string str, bool flag)
{
    vector<string> temp;
    string s = "";
    int i, sz = str.size();
    for (i = 0; i < sz; i++) {
        if (str[i] != ' ') {
            s += str.substr(i, 1);
            if (i == sz - 1) temp.push_back(s);
        }
        else {
            if (flag && s == "and") {
                s = "";
                continue;
            }
            else {
                temp.push_back(s);
                s = "";

            }
        }
    }

    return temp;
}

void analyzeinfo(vector<string> str)
{
    string strarr[4][2] = {
        {str[0], "-"},
        {str[1], "-"}, 
        {str[2], "-"}, 
        {str[3], "-"}
    };
    string key = "";
    int i, j, k, l;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                for (l = 0; l < 2; l++) {
                    key = strarr[0][i] + strarr[1][j] + strarr[2][k] + strarr[3][l];
                    possiblekey.insert(key);
                    database[key].push_back(stoi(str[4]));
                }
            }
        }
    }
}

int analyzequery(vector<string> str)
{
    //검색을 bs로 하면 통과할 수 있을까?
    string key = "";
    int i, sz, score = stoi(str[4]), cnt = 0;
    int left, mid, right;
    for (i = 0; i < 4; i++)
        key += str[i];

    left = 0;
    right = database[key].size() - 1;
    while (left <= right) {     
        mid = (left + right) / 2;
        if (database[key][mid] < score) left = mid + 1;
        else right = mid - 1;
    }
    
    return database[key].size() - left;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int i, sz = info.size();

    for(i = 0; i < sz; i++)
        analyzeinfo(strcat(info[i], false));

    for (set<string>::iterator iter = possiblekey.begin(); iter != possiblekey.end(); ++iter) {
        sort(database[*iter].begin(), database[*iter].end());
    }
    sz = query.size();
    for (i = 0; i < sz; i++)
        answer.push_back(analyzequery(strcat(query[i], true)));
    
    return answer;
}
