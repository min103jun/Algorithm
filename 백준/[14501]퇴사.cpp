#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef struct dat {
	int day;
	int pay;
	dat(int _day, int _pay) {
		day = _day;
		pay = _pay;
	}
};
vector<dat> schedule;
int N, answer = 0;

void DFS(int index, int sum)
{

	for (int i = index; i < N; i++) {
		if (i + schedule[i].day <= N)
			DFS(i + schedule[i].day, sum + schedule[i].pay);
	}

	if (answer < sum)
		answer = sum;
	return;
}

void solution()
{
	int i, j, d, p;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> d >> p;
		schedule.push_back(dat(d, p));
	}

	for (i = 0; i < N; i++) {
		if(i + schedule[i].day <= N)
			DFS(i + schedule[i].day, schedule[i].pay);
	}
}

int main()
{
	solution();
	cout << answer << "\n";

	return 0 ;
}
