//소수를 구할때 3이 소수라면 3의 배수는 전부 소수에서 빼주는 방법을 반복한다.
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

bool visit[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, st, en;
	int n, temp;
	bool flag;

	cin >> st >> en;
	memset(visit, false, sizeof(bool) * en);
	for (i = st; i <= en; i++) {
		if (i == 1)
			continue;
		if (visit[i] == false) {
			flag = false;
			n = sqrt(i);
			for (j = 2; j <= n; j++) {
				if (i % j == 0) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				cout << i << "\n";
				temp = i + i;
				while (temp <= en) {
					visit[temp] = true;
					temp += i;
				}
			}
		}
	}

	return 0;
}
