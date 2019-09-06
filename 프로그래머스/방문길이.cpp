#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int solution(string dirs)
{
	int i, j, answer = 0;
	vector<string> answerlist;
	string temp, tempa, tempb;
	int prevx, prevy, x = 5, y = 5;

	for (i = 0; i < dirs.size(); i++) {
		prevx = x;
		prevy = y;
		if (dirs.substr(i, 1) == "U")
			x += -1;
		else if (dirs.substr(i, 1) == "R")
			y += 1;
		else if (dirs.substr(i, 1) == "D")
			x += 1;
		else
			y += -1;
		if (x < 0 || x > 10 || y < 0 || y > 10) {
			x = prevx;
			y = prevy;
			continue;
		}
		tempa = to_string(prevx) + to_string(prevy);
		tempb = to_string(x) + to_string(y);
		if (tempa.compare(tempb) < 0)
			temp = tempa + tempb;
		else
			temp = tempb + tempa;
		if (find(answerlist.begin(), answerlist.end(), temp) == answerlist.end()) {
			answer++;
			answerlist.push_back(temp);
		}
	}
	return answer;
}
