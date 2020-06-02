#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int i, j, ret, sz, cnt;
	int answer = 9999;
	string a, b;

	cin >> a >> b;
	ret = b.size() - a.size();
	sz = a.size();
	for (i = 0; i <= ret; i++) {
		cnt = 0;
		for (j = 0; j < sz; j++) {
			if (a[j] != b[i + j])
				++cnt;
		}
		answer = min(answer, cnt);
	}

	cout << answer << endl;
	return 0;
}
