#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, string> graph;
map<string, pair<int, int>> profit; //(순수익, 가입수익)

void DFS(string name, int price) 
{
    if (name == "-")
        return;
    else {
        int temp = price / 10;
        profit[name].second += (price - temp);
        if (temp > 0)
            DFS(graph[name], temp);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int i, temp, enrollsize = enroll.size(), sellersize = seller.size();

    for (i = 0; i < enrollsize; i++) {
        graph[enroll[i]] = referral[i];
        profit[enroll[i]] = make_pair(0, 0);
    }

    for (i = 0; i < sellersize; i++) {
        profit[seller[i]].first += amount[i] * 100;
        temp = amount[i] * 10;
        profit[seller[i]].first -= temp;
        if(temp > 0)
            DFS(graph[seller[i]], temp);
    }//얘들 위주로 시작해야함
    for (i = 0; i < enrollsize; i++) {
        answer.push_back(profit[enroll[i]].first + profit[enroll[i]].second);
    }

    return answer;
}

int main()
{
    solution(
        { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" },
        { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" },
        { "young", "john", "tod", "emily", "mary" },
        { 12, 4, 2, 5, 10 }
    );
    return 0;
}
