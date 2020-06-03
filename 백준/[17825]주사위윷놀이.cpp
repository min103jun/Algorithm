#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int board[41] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18,20,22,24,26,28,30,32,34,36,38,40, 0,
				10, 13, 16, 19, 25,
				20, 22, 24, 25,
				30, 28, 27, 26, 25,
				25, 30, 35, 40, 0 };
int dir[10], answer = 0;
int pos[4] = { 0,0,0,0 }, score[4] = { 0,0,0,0 };

void DFS(int index)
{
	if (index == 10) {
		answer = max(answer, score[0] + score[1] + score[2] + score[3]);
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			//어떤 말을 움직일지 모르니 전부 해봐야한다.
			if (pos[i] == 21 || pos[i] == 40)
				continue; //끝에 도착한 말은 움직이지 않는다.
			
			//DFS이후 원상복귀를 위한 위치와 점수 저장.
			int temppos = pos[i];
			int tempscore = score[i];
			bool flag = false, flag2 = false;
			
			int head = temppos;
			for (int j = 1; j <= dir[index]; j++) {
				head += 1;
				if (head == 21 || head == 40) {
					head = 40;
					flag = true; //움직이다 끝에 도착하면 멈춘다.
					break;
				}
				else if (head == 26 || head == 30 || head == 35)
					head = 36;
			}
			if (!flag) {
				//끝에 도착하지 않은 말들. 전환되어야할 위치로 가면 방향을 바꿔준다.
				if (head == 5)
					head = 22;
				else if (head == 10)
					head = 27;
				else if (head == 15)
					head = 31;
				else if (head == 26 || head == 30 || head == 35)
					head = 36;
				else if (head == 20)
					head = 39;
				for (int j = 0; j < 4; j++) {
					if (j == i)
						continue;
					if (head == pos[j]) {
						flag2 = true; //flag2 가 true라면 그 말은 다른말이랑 겹친다.
						break;
					}
				}
			}
			if (!flag2) {
				pos[i] = head;
				score[i] += board[head];
				DFS(index + 1);
				pos[i] = temppos;
				score[i] = tempscore;
			}
		}
	}
}

int main()
{
	int i, j;

	for (i = 0; i < 10; i++) {
		cin >> dir[i];
	}

	DFS(0);
	
	cout << answer << endl;
	return 0;
}
