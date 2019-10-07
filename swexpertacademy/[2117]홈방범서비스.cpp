#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solution()
{
	int i, j, k, l, answer = 0, tempanswer = 0;
	int N, M, K, temp, cost, cnt, distance, profit;
	vector<pair<int, int>> pos;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 1)
				pos.push_back(make_pair(i, j));
		}
	}

	for(i = N + 1; i > 0; i--){
		cost = i * i + (i - 1) * (i - 1);
		if (cost < answer)
			break;
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				cnt = 0;
				for (l = 0; l < pos.size(); l++) {
					distance = abs(pos[l].first - j) + abs(pos[l].second - k);
					if (distance < i)
						cnt++;
				}
				profit = (M * cnt) - cost;
				if (profit >= 0 && answer < cnt) {
					answer = cnt;
				}
			}
		}
	}

	return answer;
}

int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++)
		cout << "#" << i << " " << solution() << "\n";

	return 0;
}
