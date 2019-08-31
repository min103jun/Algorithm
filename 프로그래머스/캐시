#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int i, j, answer = 0, flag = 0;
	string temp;
	vector<string> Q;

	if (cacheSize == 0)
		return 5 * cities.size();
	
	for (i = 0; i < cities.size(); i++) {
		for (j = 0; j < cities[i].size(); j++)
			cities[i][j] = tolower(cities[i][j]);
		for (j = 0; j < Q.size(); j++) {
			if (Q[j].compare(cities[i]) == 0) {
				flag = 1; // 만약에 찾았다.
				break;
			}
		}
		if (flag == 1) {
			temp = Q[j];
			Q.erase(Q.begin() + j);
			Q.push_back(temp);
			answer += 1;
		}
		else {
			answer += 5;
			if (Q.size() < cacheSize)
				Q.push_back(cities[i]);
			else if (Q.size() == cacheSize) {
				Q.erase(Q.begin());
				Q.push_back(cities[i]);
			}
		}
		flag = 0;
	}

	return answer;
}
