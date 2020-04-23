#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> nothear;
vector<string> answer;

bool compare(const string& a, const string& b)
{
	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, n, m;
	int l, r, mid, sz = 0;
	string str;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> str;
		nothear.push_back(str);
	}
	sort(nothear.begin(), nothear.end(), compare);

	for (i = 0; i < m; i++) {
		cin >> str;
		l = 0;
		r = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (nothear[mid] == str) {
				answer.push_back(str);
				++sz;
				break;
			}
			else if (str < nothear[mid]) {
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
	}

	sort(answer.begin(), answer.end(), compare);
	cout << sz << endl;
	for (i = 0; i < sz; i++)
		cout << answer[i] << endl;

	return 0;
}
