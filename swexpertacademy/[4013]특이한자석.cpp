#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution()
{
	int i, j, num, spin, pos, temp;
	vector<vector<int>> spinner(4, vector<int>(8, 0));
	int rotate[4];

	cin >> num;
	for (i = 0; i < 4; i++) 
		for (j = 0; j < 8; j++)
			cin >> spinner[i][j];

	for (i = 0; i < num; i++) {
		cin >> spin >> pos;
		spin--;
		rotate[spin] = pos;
		for (j = spin - 1; j >= 0; j--) {
			//왼쪽
			if (spinner[j][2] != spinner[j + 1][6])
				rotate[j] = (-1) * rotate[j + 1];
			else
				rotate[j] = 0;
		}
		for (j = spin + 1; j < 4; j++) {
			if (spinner[j - 1][2] != spinner[j][6])
				rotate[j] = (-1) * rotate[j - 1];
			else
				rotate[j] = 0;
		}
		for (j = 0; j < 4; j++) {
			if (rotate[j] == 1) {
				spinner[j].insert(spinner[j].begin(), spinner[j][7]);
				spinner[j].erase(spinner[j].end() - 1);
			}
			else if (rotate[j] == -1) {
				spinner[j].push_back(spinner[j][0]);
				spinner[j].erase(spinner[j].begin());
			}
		}
	}

	return spinner[0][0] + (spinner[1][0] * 2) + (spinner[2][0] * 4) + (spinner[3][0] * 8);
}

int main()
{
	int i, T;

	cin >> T;
	for (i = 1; i <= T; i++)
		cout << "#" << i << " " << solution() << "\n";

	return 0;
}
