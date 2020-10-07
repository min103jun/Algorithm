#include <string>
#include <stack>

using namespace std;

stack<char> S;

int solution(string s)
{
    int i = 0, sz = s.size(), cnt = 0;
    for (i = 0; i < sz; i++) {
        if (!S.empty() && S.top() == s[i]) {
            cnt += 2;
            S.pop();
        }
        else {
            S.push(s[i]);
        }
    }
    if (cnt == sz)
        return 1;
    else
        return 0;
}
