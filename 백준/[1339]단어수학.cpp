#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

vector<pair<char, int>> vec;
int num[26];

bool compare(const pair<char, int>& a, const pair<char, int>& b)
{
	return a.second > b.second;
}

int main()
{
	int i, j, N, ten, answer = 0;
	string str;

	cin >> N;
	memset(num, 0, sizeof(int) * 26);
	for (i = 0; i < N; i++) {
		cin >> str;
		ten = 1;
		for (j = str.size() - 1; j >= 0; --j) {
			num[str[j] - 'A'] += ten;
			ten *= 10;
		}
	}
	
	for (i = 0; i < 26; i++) {
		if (num[i] > 0) {
			vec.push_back(make_pair('A' + i, num[i]));
		}
	}

	sort(vec.begin(), vec.end(), compare);
	ten = 9;
	for (i = 0; i < vec.size(); i++) {
		answer += (vec[i].second * ten);
		--ten;
	}

	cout << answer << endl;
	return 0;
}
