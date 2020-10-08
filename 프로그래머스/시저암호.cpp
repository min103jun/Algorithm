#include <string>
#include <vector>

using namespace std;

int a[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z'};
int A[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z'};
string solution(string s, int n) {
    string answer = "";
    int i, idx, sz= s.size();
    for(i = 0; i< sz;i++) {
        if(s[i] == ' ') continue;
        else if('a' <= s[i] && s[i] <= 'z') {
            idx = s[i] - 'a';
            s[i] = a[(idx + n) % 26];
        }
        else if('A' <= s[i] && s[i] <= 'Z') {
            idx = s[i] - 'A';
            s[i] = A[(idx + n) % 26];
        }
    }
    return s;
}
