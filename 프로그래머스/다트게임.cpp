#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int solution(string dartResult) {
	int i, j, answer = 0, index = 0;
	vector<string> resultsplit;
	vector<int> answerarr;
	string opt = "", mult_s;
	double num, mult_d;

	for (i = 1; i < dartResult.size(); i++) {
		if (48 <= dartResult[i] && dartResult[i] <= 57) {
			if (dartResult[i] == 48) {
				if (dartResult[i - 1] != 49) {
					resultsplit.push_back(dartResult.substr(index, i - index));
					index = i;
				}
			}
			else {
				resultsplit.push_back(dartResult.substr(index, i - index));
				index = i;
			}
		}
	}
	resultsplit.push_back(dartResult.substr(index, i - index));
	
	for (i = 0; i < resultsplit.size(); i++) {
		if (resultsplit[i][1] == 48) {
			num = 10;
			mult_s = resultsplit[i].substr(2, 1);
			index = 3;
		}
		else {
			num = stoi(resultsplit[i].substr(0, 1));
			mult_s = resultsplit[i].substr(1, 1);
			index = 2;
		}
		if (index != resultsplit[i].size())
			opt = resultsplit[i].substr(index, 1);
		
		if (mult_s == "S")
			mult_d = 1;
		else if (mult_s == "D")
			mult_d = 2;
		else
			mult_d = 3;

		if (opt == "*") {
			if (i == 0)
				answerarr.push_back((int)pow(double(num), mult_d) * 2);
			else {
				answerarr[i - 1] *= 2;
				answerarr.push_back((int)pow(double(num), mult_d) * 2);
			}
		}
		else if (opt == "#")
			answerarr.push_back((int)pow(double(num), mult_d) * (-1));
		else if (opt == "")
			answerarr.push_back((int)pow(double(num), mult_d));
		opt = "";
	}
		
	for (i = 0; i < 3; i++)
		answer += answerarr[i];
	return answer;
}
