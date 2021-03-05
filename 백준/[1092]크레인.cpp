#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> crain, box;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, c, b, mc = 0;
	int answer = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> c;
		mc = max(mc, c);
		crain.push_back(c);
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> b;
		if (b > mc) {
			cout << -1 << endl;
			return 0;
		}
		box.push_back(b);
	}
	sort(crain.begin(), crain.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	while (!box.empty()) {
		for (i = 0; i < crain.size(); i++) {
			for (j = 0; j < box.size(); j++) {
				if (box[j] <= crain[i]) {
					box.erase(box.begin() + j);
					--j;
					break;
				}
			}
		}
		++answer;
	}
	cout << answer << endl;
	return 0;
}
