#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, answer = 0;
int score[50][9];
vector<int> striker(9, -1);

void check()
{
	//striker엔 지금 순서가 들어있다. (0번타자 ~ 8번타자)
	int i, j, num = 0, stk, out = 0, sc, temp;
	int ss_idx = 0, get = 0, len;
	queue<int> ss;

	for (i = 0; i < N; i++) {
		//N이닝 까지 경기를 뛴다.
		while (out < 3) {
			stk = striker[num];
			sc = score[i][stk];//그 이닝때 그 선수가 얻는 점수.
			if (sc == 0) {
				out++;
			}
			else {
				len = ss.size();
				for (j = 0; j < len; j++) {
					temp = ss.front() + sc;
					ss.pop();
					if (temp >= 4) {
						get++;
					}
					else
						ss.push(temp);
				}
				if (sc == 4)
					get++;
				else
					ss.push(sc);
			}
			num = (num + 1) % 9;
		}
		while (!ss.empty())
			ss.pop();
		out = 0;
	}
	if (answer < get)
		answer = get;
}

void DFS(int cnt)
{
	if (cnt == 9) {
		check();
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (striker[i] == -1) {
			striker[i] = cnt;
			DFS(cnt + 1);
			striker[i] = -1;
		}
	}
}
void solution()
{
	int i, j;

	cin >> N;
	for (i = 0; i < N; i++) {
		for (j = 0; j < 9; j++)
			cin >> score[i][j];
	}

	striker[3] = 0;
	for (int i = 0; i < 9; i++) {
		if (striker[i] == -1) {
			striker[i] = 1;
			DFS(2);
			striker[i] = -1;
		}
	}
}

int main()
{
	solution();
	cout << answer << "\n";
	return 0;
}
