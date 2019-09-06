#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int i, j, answer = 0, index = 1, size;
	vector<int> emptyarr;

	for (i = 0; i < stations.size(); i++) {
        if(stations[i] - w  > index)
		    emptyarr.push_back(stations[i] - w - index);
		index = stations[i] + w + 1;
	}
	if (index <= n)
		emptyarr.push_back(n - index + 1);

	size = 2 * w + 1;
	for (i = 0; i < emptyarr.size(); i++)
		answer += (int)(ceil((double)emptyarr[i] / size));
	return answer;
}
