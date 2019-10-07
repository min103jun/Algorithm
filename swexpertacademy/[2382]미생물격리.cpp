#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef struct virus {
	int x;
	int y;
	int m;
	int d;
	int prevm;
}virus;

int solution()
{
	int map[100][100];
	int dirarr[100][100];
	virus tempvirus;
	vector<virus> arr, temparr;
	int i, j, k, N, M, K, x, y, m, d, answer = 0, len;
	int tempx, tempy;
	int dir[5][2] = { {0, 0}, {-1, 0}, {1, 0},{0, -1},{0 ,1} };

	cin >> N >> M >> K;
	for (i = 0; i < K; i++) {
		cin >> tempvirus.x >> tempvirus.y >> tempvirus.m >> tempvirus.d;
		arr.push_back(tempvirus);
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			memset(map[j], -1, sizeof(int) * N);
		//바이러스 위치 파악
		len = arr.size();
		for (j = 0; j < len; j++) {
			tempvirus = arr.front();
			arr.erase(arr.begin());
			tempx = tempvirus.x + dir[tempvirus.d][0];
			tempy = tempvirus.y + dir[tempvirus.d][1];
			if (tempx == 0 || tempy == 0 || tempx == N - 1 || tempy == N - 1) {
				tempvirus.m = tempvirus.m / 2;
				if (tempx == 0)
					tempvirus.d = 2;
				else if (tempx == N - 1)
					tempvirus.d = 1;
				else if (tempy == 0)
					tempvirus.d = 4;
				else
					tempvirus.d = 3;
			}
			tempvirus.x = tempx;
			tempvirus.y = tempy;
			if(tempvirus.m != 0)
				arr.push_back(tempvirus);
		}

		//바이러스 이동
		for (j = 0; j < arr.size(); j++) {
			tempx = arr[j].x;
			tempy = arr[j].y;
			if (map[tempx][tempy] == -1) {
				map[tempx][tempy] = temparr.size();
				temparr.push_back(arr[j]);
				temparr[temparr.size() - 1].prevm = temparr[temparr.size() - 1].m;
			}
			else {
				//무언가 있을 때.
				temparr[map[tempx][tempy]].m += arr[j].m;
				if (temparr[map[tempx][tempy]].prevm < arr[j].m) {
					temparr[map[tempx][tempy]].prevm = arr[j].m;
					temparr[map[tempx][tempy]].d = arr[j].d;
				}
			}
		}
		//복사
		arr.erase(arr.begin(), arr.end());
		arr = temparr;
		temparr.erase(temparr.begin(), temparr.end());
	}

	for (i = 0; i < arr.size(); i++) {
		answer += arr[i].m;
	}

	return answer;
}

int main()
{
	int i, T;
	cin >> T;
	for (i = 1; i <= T; i++) {
		cout << "#" << i << " " << solution() << "\n";
	}
	return 0;
}
