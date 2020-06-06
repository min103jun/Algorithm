#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef struct vir {
	int x;
	int y;
	int d;
	int k;
	bool l;
	vir(int _x, int _y, int _d, int _k) {
		x = _x;
		y = _y;
		d = _d;
		k = _k;
		l = true;
	}
}vir;

int N, dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
vector<vir> virus;
int map[4002][4002];
void init()
{
	virus.clear();
}

bool check()
{
	for (int i = 0; i < N; i++)
	{
		if (virus[i].l == true)
		{
			return false;
		}
	}
	return true;
}

int solution()
{
	int i, j, k, answer = 0;
	int tx, ty, td, tk, cnt = 0;

	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> tx >> ty >> td >> tk;
		virus.push_back(vir((tx + 1000) * 2, (ty + 1000) * 2, td, tk));
	}

	while (true) {
		if (check())
			break;

		for (i = 0; i < N; i++) {
			if (virus[i].l == true) {
				virus[i].x += dir[virus[i].d][0];
				virus[i].y += dir[virus[i].d][1];

				tx = virus[i].x; ty = virus[i].y;
				if (tx >= 0 && ty >= 0 && tx < 4002 && ty < 4002) {
					map[tx][ty] += 1;
					map[virus[i].x - dir[virus[i].d][0]][virus[i].y-dir[virus[i].d][1]] = 0;
				}
				else {
					virus[i].l = false;
					map[virus[i].x - dir[virus[i].d][0]][virus[i].y - dir[virus[i].d][1]] = 0;
					++cnt;
				}
			}
		}

		for (i = 0; i < N; i++) {
			tx = virus[i].x; ty = virus[i].y;
			if (virus[i].l == true && map[tx][ty] >= 2) {
				answer += virus[i].k;
				virus[i].l = false;
				map[tx][ty] = 0;
				++cnt;
				for (j = 0; j < N; j++) {
					if (i == j || virus[j].l == false) continue;

					if (virus[j].x == tx && virus[j].y == ty) {
						answer += virus[j].k;
						virus[j].l = false;
						++cnt;
					}
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
	for (i = 1; i <= T; i++) {
		init();
		cout << "#" << i << " " << solution() << endl;
	}
	return 0;
}
