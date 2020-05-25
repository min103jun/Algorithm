#include <iostream>

using namespace std;

int sz, map[128][128];
int white = 0, blue = 0;

void check(int x, int y, int n)
{
	int i, j, tmp;
	bool flag = true;
	tmp = map[x][y];
	for (i = x; i < x + n; i++) {
		for (j = y; j < y + n; j++) {
			if (map[i][j] != tmp) {
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}

	if (flag == true) {
		if (tmp == 0)
			++white;
		else
			++blue;
	}
	else {
		check(x, y, n / 2);
		check(x, y + n / 2, n / 2);
		check(x + n / 2, y, n / 2);
		check(x + n / 2, y + n / 2, n / 2);
	}
}

int main()
{
	int i, j, temp;
	bool flag = false;

	cin >> sz;
	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz; j++) {
			cin >> map[i][j];		
		}
	}

	check(0, 0, sz);
	cout << white << "\n" << blue << "\n";

	return 0;
}
