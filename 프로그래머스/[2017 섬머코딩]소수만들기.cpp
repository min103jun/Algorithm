#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int all_cnt = 0;
bool checkprime(int num)
{
	if (num % 2 == 0)
		return false;

	int temp = (int)sqrt(num);
	for (int i = temp; i >= 3; i--)
		if (num % i == 0)
			return false;

	return true;
}

void DFS(vector<int> nums, int index, int cnt, int sum)
{
	int i;
	if (cnt == 3) {
		if (checkprime(sum))
			all_cnt++;
		return;
	}

	for (i = index; i < nums.size(); i++)
		DFS(nums, i + 1, cnt + 1, sum + nums[i]);

}

int solution(vector<int> nums)
{
	int i, answer;

	for (i = 0; i < nums.size(); i++) 
		DFS(nums, i + 1, 1, nums[i]);
	
	answer = all_cnt;
	return answer;
}
