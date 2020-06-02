#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int i, X, sum, temp;
	vector<int> stick;

	stick.push_back(64);
	cin >> X;

	while (true) {
		sum = 0;
		for (i = 0; i < stick.size(); i++)
			sum += stick[i];

		if (sum == X)
			break;
		if (sum > X) {
			sort(stick.begin(), stick.end());
			temp = stick[0] / 2;
			stick.erase(stick.begin());
			stick.push_back(temp);
			if (sum - temp < X)
				stick.push_back(temp);
		}		
	}

	cout << stick.size() << endl;
	return 0;
}
