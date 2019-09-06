#include <iostream>

using namespace std;

int solution(int N)
{
	int i, answer = 0;

	while (N != 0) {
		if (N % 2 == 0)
			N /= 2;
		else {
			answer++;
			N = (N - 1) / 2;
		}
	}
	return answer;
}
