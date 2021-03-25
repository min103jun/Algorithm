#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, vector<int>> database;

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
                    database[key].push_back(stoi(str[4]));
                }
            }
        }
    }
}

int analyzequery(vector<string> str)
{
    string key = "";
    int i, sz, score = stoi(str[4]), cnt = 0;

    for (i = 0; i < 4; i++)
        key += str[i];

    sz = database[key].size();
    for (i = 0; i < sz; i++) {
        if (database[key][i] >= score) ++cnt;
    }
    return cnt;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int i, sz = info.size();

    for(i = 0; i < sz; i++)
        analyzeinfo(strcat(info[i], false));

    sz = query.size();
    for (i = 0; i < sz; i++)
        answer.push_back(analyzequery(strcat(query[i], true)));
    
    return answer;
}
