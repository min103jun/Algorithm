#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string binary(int n, int num)
{
    string temp = "";
    int i, zero;
    
    while(num != 0) {
        temp += to_string(num % 2);
        num /= 2;
    }
    
    if(temp.size() < n) {
        zero = n - temp.size();
        for(i = 0; i < zero; i++) 
            temp.append("0");
    }
    reverse(temp.begin(), temp.end());

    return temp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string temp;
    vector<string> map1, map2;
    int i, j;
    
    for(i = 0; i < n; i++) {
        map1.push_back(binary(n, arr1[i]));
        map2.push_back(binary(n, arr2[i]));
    }
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(map1[i].substr(j, 1) == "0" && map2[i].substr(j, 1) == "0")
                temp.append(" ");
            else
                temp.append("#");
        }
        answer.push_back(temp);
        temp = "";
    }
    return answer;
}
