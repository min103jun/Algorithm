#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
using namespace std;

int answer = ((-1) * (int)pow(2, 31));
int N, numnum, numop;
string eq;
vector<pair<int, int>> pren;

void check()
{
	int i, j, idx = 0, x, y, result;
	vector<int> num;
	vector<string> op;

	for (i = 0; i < N; i++) {
		if (i % 2 == 0)
			num.push_back(stoi(eq.substr(i, 1)));
		else
			op.push_back(eq.substr(i, 1));
	}

	for (i = 0; i < pren.size(); i++) {
		x = pren[i].first - idx;
		y = pren[i].second - idx;
		result = num[x];
		for (j = x; j < y; j++) {
			if (op[j] == "+")
				result += num[j + 1];
			else if (op[j] == "-")
				result -= num[j + 1];
			else
				result *= num[j + 1];
		}
		idx += y - x;
		num.erase(num.begin() + x, num.begin() + y + 1);
		op.erase(op.begin() + x, op.begin() + y);
		num.insert(num.begin() + x, result);
	}
	result = num[0];
	for (j = 0; j < op.size(); j++) {
		if (op[j] == "+")
			result += num[j + 1];
		else if (op[j] == "-")
			result -= num[j + 1];
		else
			result *= num[j + 1];
	}

	//cout << result << "\n";
	if (answer < result)
		answer = result;
}

void DFS(int start)
{
	for (int i = start; i < numnum - 1; i++) {
		pren.push_back(make_pair(i, i + 1));
		DFS(i + 2);
		pren.erase(pren.end() - 1);
	}

	check();
	if (start >= N - 1)
		return;
}

void solution()
{
	int i, j;

	cin >> N;
	cin >> eq;
	if (N == 1) {
		answer = stoi(eq);
		return;
	}
	numnum = N / 2 + 1;
	numop = N / 2;
	for (i = 0; i < numnum - 1; i++) {
		pren.push_back(make_pair(i, i + 1));
		DFS(i + 2);
		pren.erase(pren.end() - 1);
	}
}

int main()
{
	solution();
	cout << answer << "\n";
	system("pause");
	return 0;
}
