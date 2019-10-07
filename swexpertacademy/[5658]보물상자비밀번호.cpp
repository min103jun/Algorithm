#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int T, m, n, i, j, k, cnt, index;
	string temp, str;
	vector<string> strarr;
	vector<int> answerarr;
	cin >> T;
	for (i = 1; i <= T; i++) {
		cin >> m >> n;
		cin >> str;
		cnt = m / 4;
		for(j = 0; j < cnt; j++) {
			str = str.substr(m - 1, 1) + str.substr(0, m - 1);
			for (k = 0; k < 4; k++) 
				strarr.push_back(str.substr(k * cnt, cnt));		
		}
		for (j = 0; j < strarr.size(); j++)
			answerarr.push_back(strtol(strarr[j].c_str(), NULL, 16));
		sort(answerarr.begin(), answerarr.end(), compare);
		answerarr.erase(unique(answerarr.begin(), answerarr.end()), answerarr.end());
		cout << "#" << i << " " << answerarr[n - 1] << endl;
		strarr.erase(strarr.begin(), strarr.end());
		answerarr.erase(answerarr.begin(), answerarr.end());
	}

	return 0;
}
