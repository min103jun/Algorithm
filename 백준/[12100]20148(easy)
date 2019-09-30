#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

void move_left(int**, int, int);
void move_right(int**, int, int);
void move_up(int**, int, int);
void move_down(int**, int, int);

int max_num = 0;
int **check_use;


void check(int** arr, int num)
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (max_num < arr[i][j])
				max_num = arr[i][j];
		}
	}
}

void copy(int **arr1, int **arr2, int num)
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			arr2[i][j] = arr1[i][j];
		}
	}
}

void first(int** arr, int num, int count)
{
	move_left(arr, num, count);
	move_right(arr, num, count);
	move_up(arr, num, count);
	move_down(arr, num, count);
}


void move_left(int **arr, int num, int count)
{
	int i, j, idx = 1;
	int **temp;

	for (i = 0; i < num; i++)
		memset(check_use[i], 0, sizeof(int) * num);
	temp = new int*[num];
	for (i = 0; i < num; i++) {
		temp[i] = new int[num];
	}
	copy(arr, temp, num);
	for (i = 0; i < num; i++) {
		for (j = 1; j < num; j++) {
			if (temp[i][j] == 0 && j < idx)
				idx = j;
			if (temp[i][j] != 0) {
				if (temp[i][j] == temp[i][idx - 1]) {
					if (check_use[i][idx - 1] == 0) {
						temp[i][j] = 0;
						temp[i][idx - 1] *= 2;
						check_use[i][idx - 1] = 1;
					}
					else {
						temp[i][idx] = temp[i][j];
						temp[i][j] = 0;
						idx += 1;
					}
				}
				else {
					if (temp[i][0] == 0) {
						temp[i][0] = temp[i][j];
						temp[i][j] = 0;
					}
					else {
						if (temp[i][idx] != 0) {
							idx += 1;
							continue;
						}
						else {
							temp[i][idx] = temp[i][j];
							temp[i][j] = 0;
							idx += 1;
						}
					}
				}
			}
		}
		idx = 1;
	}

	if (count == 1) {
		check(temp, num);
		return;
	}


	move_left(temp, num, count - 1);
	move_right(temp, num, count - 1);
	move_up(temp, num, count - 1);
	move_down(temp, num, count - 1);
}

void move_right(int **arr, int num, int count)
{
	int i, j, idx = num - 2;
	int **temp;
	temp = new int*[num];
	for (i = 0; i < num; i++) {
		temp[i] = new int[num];
	}
	copy(arr, temp, num);
	for (i = 0; i < num; i++)
		memset(check_use[i], 0, sizeof(int) * num);

	for (i = 0; i < num; i++) {
		for (j = num - 2; j >= 0; j--) {
			if (temp[i][j] == 0 && j > idx)
				idx = j;
			if (temp[i][j] != 0) {
				if (temp[i][j] == temp[i][idx + 1]) {
					if (check_use[i][idx + 1] == 0) {
						temp[i][j] = 0;
						temp[i][idx + 1] *= 2;
						check_use[i][idx + 1] = 1;
					}
					else {
						temp[i][idx] = temp[i][j];
						temp[i][j] = 0;
						idx -= 1;
					}
				}
				else {
					if (temp[i][num - 1] == 0) {
						temp[i][num - 1] = temp[i][j];
						temp[i][j] = 0;
					}
					else {
						if (temp[i][idx] != 0) {
							idx -= 1;
							continue;
						}
						else {
							temp[i][idx] = temp[i][j];
							temp[i][j] = 0;
							idx -= 1;
						}
					}
				}
			}
		}
		idx = num - 2;
	}

	if (count == 1) {
		check(temp, num);
		return;
	}

	move_left(temp, num, count - 1);
	move_right(temp, num, count - 1);
	move_up(temp, num, count - 1);
	move_down(temp, num, count - 1);
}

void move_up(int **arr, int num, int count)
{
	int i, j, idx = 1;
	int **temp;
	temp = new int*[num];
	for (i = 0; i < num; i++) {
		temp[i] = new int[num];
	}
	copy(arr, temp, num);
	for (i = 0; i < num; i++)
		memset(check_use[i], 0, sizeof(int) * num);

	for (i = 0; i < num; i++) {
		for (j = 1; j < num; j++) {
			if (temp[j][i] == 0 && j < idx)
				idx = j;
			if (temp[j][i] != 0) {
				if (temp[j][i] == temp[idx - 1][i]) {
					if (check_use[idx - 1][i] == 0) {
						temp[j][i] = 0;
						temp[idx - 1][i] *= 2;
						check_use[idx - 1][i] = 1;
					}
					else {
						temp[idx][i] = temp[j][i];
						temp[j][i] = 0;
						idx += 1;
					}
				}
				else {
					if (temp[0][i] == 0) {
						temp[0][i] = temp[j][i];
						temp[j][i] = 0;
					}
					else {
						if (temp[idx][i] != 0) {
							idx += 1;
							continue;
						}
						else {
							temp[idx][i] = temp[j][i];
							temp[j][i] = 0;
							idx += 1;
						}
					}
				}
			}
		}
		idx = 1;
	}

	if (count == 1) {
		check(temp, num);
		return;
	}

	move_left(temp, num, count - 1);
	move_right(temp, num, count - 1);
	move_up(temp, num, count - 1);
	move_down(temp, num, count - 1);
}

void move_down(int **arr, int num, int count)
{
	int i, j, idx = num - 2;
	int **temp;
	temp = new int*[num];
	for (i = 0; i < num; i++) {
		temp[i] = new int[num];
	}
	copy(arr, temp, num);
	for (i = 0; i < num; i++)
		memset(check_use[i], 0, sizeof(int) * num);

	for (i = 0; i < num; i++) {
		for (j = num - 2; j >= 0; j--) {
			if (temp[j][i] == 0 && j > idx)
				idx = j;
			if (temp[j][i] != 0) {
				if (temp[j][i] == temp[idx + 1][i]) {
					if (check_use[idx + 1][i] == 0) {
						temp[j][i] = 0;
						temp[idx + 1][i] *= 2;
						check_use[idx + 1][i] = 1;
					}
					else {
						temp[idx][i] = temp[j][i];
						temp[j][i] = 0;
						idx -= 1;
					}
				}
				else {
					if (temp[num - 1][i] == 0) {
						temp[num - 1][i] = temp[j][i];
						temp[j][i] = 0;
					}
					else {
						if (temp[idx][i] != 0) {
							idx -= 1;
							continue;
						}
						else {
							temp[idx][i] = temp[j][i];
							temp[j][i] = 0;
							idx -= 1;
						}
					}
				}
			}
		}
		idx = num - 2;
	}

	if (count == 1) {
		check(temp, num);
		return;

	}

	move_left(temp, num, count - 1);
	move_right(temp, num, count - 1);
	move_up(temp, num, count - 1);
	move_down(temp, num, count - 1);
}

int main()
{
	int num, i, j, temp;
	int **arr;

	cin >> num;
	arr = new int*[num];
	for (i = 0; i < num; i++)
		arr[i] = new int[num];
	for (i = 0; i < num; i++)
		for (j = 0; j < num; j++)
			cin >> arr[i][j];

	check_use = new int*[num];
	for (i = 0; i < num; i++)
		check_use[i] = new int[num];

	first(arr, num, 5);

	cout << max_num << "\n";

	return 0;
}
