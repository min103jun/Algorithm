#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef struct shark {
	int s;
	int d;
	int z;
}shark;

int main()
{
	int i, j, answer = 0;
	int r, c, s, d, z, x, y, num;
	int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	map<pair<int, int>, shark> M, tempM;
	pair<int, int> pos;

	cin >> x >> y >> num;
	for (i = 0; i < num; i++) {
		shark temp;
		cin >> r >> c >> temp.s >> temp.d >> temp.z;
		temp.d--;
		pos = make_pair(r - 1, c - 1);
		M[pos] = temp;
	}

	for (j = 0; j < y; j++) {
		for (i = 0; i < x; i++) {
			pos = make_pair(i, j);
			if (M.find(pos) != M.end()) {
				answer += M[pos].z;
				M.erase(pos);
				break;
			}
		}

		for (map<pair<int, int>, shark>::iterator iter = M.begin(); iter != M.end(); iter++) {
			pos = iter->first;
			shark temp = iter->second;
			int tempx = pos.first + (dir[temp.d][0] * temp.s);
			int tempy = pos.second + (dir[temp.d][1] * temp.s);
			while (tempx < 0 || tempx >= x) {
				if (tempx < 0) {
					tempx = abs(tempx);
					temp.d = 1;
				}
				else if (tempx >= x) {
					tempx = x + x - 2 - tempx;
					temp.d = 0;
				}
			}
			while (tempy < 0 || tempy >= y) {
				if (tempy < 0) {
					tempy = abs(tempy);
					temp.d = 2;
				}
				else if (tempy >= y) {
					tempy = y + y - 2 - tempy;
					temp.d = 3;
				}
			}
			pos = make_pair(tempx, tempy);
			if (tempM.find(pos) == tempM.end())
				tempM[pos] = temp;
			else {
				if (tempM[pos].z < temp.z)
					tempM[pos] = temp;
			}
		}
		M = tempM;
		tempM.clear();
	}
	cout << answer << "\n";
	return 0;
}
