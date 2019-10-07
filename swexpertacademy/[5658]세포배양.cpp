#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;


typedef struct cell {
	int x;
	int y;
	int t;
	int st;
}cell;

int main()
{
	int iT, k;
	int sz1, sz2, t, T, i, j, answer = 0, temp, len;
	int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	int tempx, tempy, idx1, idx2;
	char map1[351][351];
	int map2[351][351];

	cin >> iT;
	for (k = 1; k <= iT; k++) {

		vector<pair<int, int>> templist;
		queue<cell> Q;
		cell tempcell;

		cin >> sz1 >> sz2 >> T;
		for (int i = 0; i < 351; i++) {
			for (j = 0; j < 351; j++) {
				map1[i][j] = 'F';
				map2[i][j] = -1;
			}
		}

		for (i = 0; i < sz1; i++) {
			for (j = 0; j < sz2; j++) {
				cin >> temp;
				if (temp != 0) {
					tempcell;
					tempcell.x = i + 150;
					tempcell.y = j + 150;
					tempcell.t = temp;
					tempcell.st = temp;
					Q.push(tempcell);
					map1[tempcell.x][tempcell.y] = 'T';
				}
			}
		}

		for (t = 1; t <= T; t++) {
			len = Q.size();
			for (i = 0; i < len; i++) {
				tempcell = Q.front();
				Q.pop();
				if (tempcell.st >= t) {
					//아직 활성화 시간이 아님
					Q.push(tempcell);
					continue;
				}
				else {
					//활성화 할 시간임.
					if (tempcell.st + tempcell.t != t) {
						Q.push(tempcell);
					}
					for (j = 0; j < 4; j++) {
						tempx = tempcell.x + dir[j][0];
						tempy = tempcell.y + dir[j][1];
						if (map1[tempx][tempy] != 'T') {
							if (map1[tempx][tempy] == 'F') {
								map1[tempx][tempy] = 'R';
								templist.push_back(make_pair(tempx, tempy));
							}
							map2[tempx][tempy] = max(map2[tempx][tempy], tempcell.t);
						}
					}
				}
			}
			for (i = 0; i < templist.size(); i++) {
				map1[templist[i].first][templist[i].second] = 'T';
				tempcell.x = templist[i].first;
				tempcell.y = templist[i].second;
				tempcell.t = map2[tempcell.x][tempcell.y];
				tempcell.st = t + tempcell.t;
				Q.push(tempcell);
			}
			templist.erase(templist.begin(), templist.end());
		}
		cout << "#" << k << " " << Q.size() << "\n";
	}

	system("pause");
	return 0;
}
