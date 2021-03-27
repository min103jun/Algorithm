#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<int, vector<string>> setmenu;
int menucount[11] = { 0 };
vector<int> order;
int N = 0, menu[26] = { 0 };

void DFS(int index, int cnt, int menunum, string setstring)
{
    if (cnt == N)
        return;
    else {
        if (cnt > 1) {
            int people = 0;
            for (int i = 0; i < order.size(); i++) {
                if ((order[i] & menunum) == menunum) ++people;
            }
            if (people > 1) {
                int sz = setstring.size();
                if (menucount[sz] < people){
                    menucount[sz] = people;
                    setmenu[sz].clear();
                    setmenu[sz].push_back(setstring);
                }
                else if (menucount[sz] == people) {
                    setmenu[sz].push_back(setstring);
                }

            }
        }
        for (int i = index; i < 26; i++) {
            if (menu[i] > 1) {
                DFS(i + 1, cnt + 1, menunum + (1 << i), setstring + alphabet[i]);
            }
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int i, j, ord = 0;

    for (i = 0; i < orders.size(); i++) {
        ord = 0;
        for (j = 0; j < orders[i].size(); j++) {
            ++menu[orders[i][j] - 'A'];
            ord += (1 << orders[i][j] - 'A');
        }
        order.push_back(ord);
    }

    N = *max_element(course.begin(), course.end());
    ++N;

    DFS(0, 0, 0, "");

    for (i = 0; i < course.size(); i++) {
        for (j = 0; j < setmenu[course[i]].size(); j++) {
            answer.push_back(setmenu[course[i]][j]);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
