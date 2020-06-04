#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct ball {
	int x;
	int y;
	string color;
	ball(int _x, int _y, string _color) {
		x = _x;
		y = _y;
		color = _color;
	}
}ball;
int N, M, answer = 9999;
char map[10][10];
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
ball red(0, 0, " "), blue(0, 0, " ");
pair<int, int> finish;

void DFS(int cnt, int d)
{
	if (cnt > 10)
		return;
	else if(cnt < answer) {
		ball first(0,0," "), second(0, 0, " "), prevred(0, 0, ""), prevblue(0,0,"");

		prevred = red;
		prevblue = blue;
		//무슨 말을 먼저 움직일 지 결정한다.
		if (d == 0 && red.y == blue.y) {
			if (red.x < blue.x) {
				first = red;
				second = blue;
			}
			else {
				first = blue;
				second = red;
			}
		}
		else if (d == 1 && red.x == blue.x) {
			if (red.y < blue.y) {
				first = blue;
				second = red;
			}
			else {
				first = red;
				second = blue;
			}
		}
		else if (d == 2 && red.y == blue.y) {
			if (red.x < blue.x) {
				first = blue;
				second = red;
			}
			else {
				first = red;
				second = blue;
			}
		}
		else if(d == 3 && red.x == blue.x) {
			if (red.y < blue.y) {
				first = red;
				second = blue;
			}
			else {
				first = blue;
				second = red;
			}
		}
		else {
			first = blue;
			second = red;
		}
		
		//첫말부터 굴려본다.
		bool flag = false;
		while (true) {
			first.x += dir[d][0]; first.y += dir[d][1];
			if (map[first.x][first.y] == 'O' && first.color == "blue")
				return; //끝에 도착했는데 blue면 이번은 틀린것이다.
			else if (map[first.x][first.y] == 'O' && first.color == "red") {
				flag = true;
				break;
			}
			else if (map[first.x][first.y] == '#' || (first.x == second.x && first.y == second.y)) {
				first.x -= dir[d][0];
				first.y -= dir[d][1];
				break;
			}
		}
		//두번째 말을 굴린다.
		while (true) {
			second.x += dir[d][0]; second.y += dir[d][1];
			if (map[second.x][second.y] == 'O' && second.color == "blue")
				return; //끝에 도착했는데 blue면 이번은 틀린것이다.
			else if (map[second.x][second.y] == 'O' && second.color == "red") {
				flag = true;
				break;
			}
			else if (map[second.x][second.y] == '#' || (second.x == first.x && second.y == first.y)) {
				second.x -= dir[d][0];
				second.y -= dir[d][1];
				break;
			}
		}
		
		if (flag) {
			//빨간말 도착. 마무리해야함
			answer = min(answer, cnt);
			return;
		}
		
		//도착하지 않았으면 또 굴려봐야함
		if (first.color == "blue") {
			blue = first;
			red = second;
		}
		else {
			blue = second;
			red = first;
		}

		if (blue.x == prevblue.x && blue.y == prevblue.y && red.x == prevred.x && red.y == prevred.y)
			return;
		
		for (int i = 0; i < 4; i++)
			DFS(cnt + 1, i);

		red = prevred;
		blue = prevblue;
	}
}

int main()
{
	int i, j;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				blue = ball(i, j, "blue");
				map[i][j] == '.';
			}
			else if (map[i][j] == 'R') {
				red = ball(i, j, "red");
				map[i][j] == '.';
			}
			else if (map[i][j] == 'O')
				finish = make_pair(i, j);
		}
	}

	for (i = 0; i < 4; i++)
		DFS(1, i);

	if (answer == 9999)
		cout << -1 << endl;
	else
		cout << answer << endl;
	return 0;
}
