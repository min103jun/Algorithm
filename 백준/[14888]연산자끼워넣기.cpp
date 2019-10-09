#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int answer1 = -1000000001, answer2 = 1000000001;
bool visited[100];
vector<char> calc;
vector<int> num;

void DFS(int cnt, int sum)
{
	if (cnt == calc.size()) {
		if (answer1 < sum)
			answer1 = sum;
		if (sum < answer2)
			answer2 = sum;
	}

	for (int i = 0; i < calc.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			if (calc[i] == '+')
				DFS(cnt + 1, sum + num[cnt + 1]);
			else if (calc[i] == '-')
				DFS(cnt + 1, sum - num[cnt + 1]);
			else if (calc[i] == '*')
				DFS(cnt + 1, sum * num[cnt + 1]);
			else {
				if (sum < 0) {
					sum = abs(sum) / num[cnt + 1];
					sum *= (-1);
					DFS(cnt + 1, sum);
				}
				else
					DFS(cnt + 1, sum / num[cnt + 1]);
			}
			visited[i] = false;
		}
	}
}

void solution()
{
	int i, j, n, temp;

	cin >> n;
	memset(visited, false, sizeof(bool) * n);
	for (i = 0; i < n; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	for (i = 0; i < 4; i++) {
		cin >> temp;
		for (j = 0; j < temp; j++) {
			if (i == 0)
				calc.push_back('+');
			else if (i == 1)
				calc.push_back('-');
			else if (i == 2)
				calc.push_back('*');
			else
				calc.push_back('/');
		}
	}

	DFS(0, num[0]);
}

int main()
{
	solution();
	cout << answer1 << "\n" << answer2 << "\n";

	return 0;
}
