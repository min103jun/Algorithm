#include <iostream>

using namespace std;

int main()
{
	int i, T, N, M, j, x, y;

	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> N >> M;
		for (j = 0; j < M; j++)
			cin >> x >> y;
		cout << N - 1 << endl;
	}

	return 0;
}
