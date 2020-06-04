#include <iostream>

using namespace std;

char U[3][3], D[3][3], F[3][3], B[3][3], L[3][3], R[3][3];
char temp[3][3];

void init()
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			U[i][j] = 'w';
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			D[i][j] = 'y';
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			F[i][j] = 'r';
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			B[i][j] = 'o';
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			L[i][j] = 'g';
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			R[i][j] = 'b';
		}
	}
}

void u(int r)
{
	int i, j, k;
	char temp1, temp2, temp3;

	for (k = 0; k < r; k++) {
		//해당 방향
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				temp[j][2 - i] = U[i][j];
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				U[i][j] = temp[i][j];
		temp1 = F[0][0]; temp2 = F[0][1]; temp3 = F[0][2];
		F[0][0] = R[0][0]; F[0][1] = R[0][1]; F[0][2] = R[0][2];
		R[0][0] = B[0][0]; R[0][1] = B[0][1]; R[0][2] = B[0][2];
		B[0][0] = L[0][0]; B[0][1] = L[0][1]; B[0][2] = L[0][2];
		L[0][0] = temp1; L[0][1] = temp2; L[0][2] = temp3;
	}
}

void d(int r)
{
	int i, j, k;
	char temp1, temp2, temp3;

	for (k = 0; k < r; k++) {
		//해당 방향
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				temp[j][2 - i] = D[i][j];
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				D[i][j] = temp[i][j];
		temp1 = F[2][0]; temp2 = F[2][1]; temp3 = F[2][2];
		F[2][0] = L[2][0]; F[2][1] = L[2][1]; F[2][2] = L[2][2];
		L[2][0] = B[2][0]; L[2][1] = B[2][1]; L[2][2] = B[2][2];
		B[2][0] = R[2][0]; B[2][1] = R[2][1]; B[2][2] = R[2][2];
		R[2][0] = temp1; R[2][1] = temp2; R[2][2] = temp3;
	}
}

void f(int r)
{
	int i, j, k;
	char temp1, temp2, temp3;

	for (k = 0; k < r; k++) {
		//해당 방향
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				temp[j][2 - i] = F[i][j];
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				F[i][j] = temp[i][j];
		temp1 = D[0][0]; temp2 = D[0][1]; temp3 = D[0][2];
		D[0][0] = R[2][0]; D[0][1] = R[1][0]; D[0][2] = R[0][0];
		R[2][0] = U[2][2]; R[1][0] = U[2][1]; R[0][0] = U[2][0];
		U[2][2] = L[0][2]; U[2][1] = L[1][2]; U[2][0] = L[2][2];
		L[0][2] = temp1; L[1][2] = temp2; L[2][2] = temp3;
	}
}

void b(int r)
{
	int i, j, k;
	char temp1, temp2, temp3;

	for (k = 0; k < r; k++) {
		//해당 방향
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				temp[j][2 - i] = B[i][j];
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				B[i][j] = temp[i][j];
		temp1 = D[2][2]; temp2 = D[2][1]; temp3 = D[2][0];
		D[2][2] = L[2][0]; D[2][1] = L[1][0]; D[2][0] = L[0][0];
		L[2][0] = U[0][0]; L[1][0] = U[0][1]; L[0][0] = U[0][2];
		U[0][0] = R[0][2]; U[0][1] = R[1][2]; U[0][2] = R[2][2];
		R[0][2] = temp1; R[1][2] = temp2; R[2][2] = temp3;
	}
}

void l(int r)
{
	int i, j, k;
	char temp1, temp2, temp3;

	for (k = 0; k < r; k++) {
		//해당 방향
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				temp[j][2 - i] = L[i][j];
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				L[i][j] = temp[i][j];
		temp1 = D[2][0]; temp2 = D[1][0]; temp3 = D[0][0];
		D[2][0] = F[2][0]; D[1][0] = F[1][0]; D[0][0] = F[0][0];
		F[2][0] = U[2][0]; F[1][0] = U[1][0]; F[0][0] = U[0][0];
		U[2][0] = B[0][2]; U[1][0] = B[1][2]; U[0][0] = B[2][2];
		B[0][2] = temp1; B[1][2] = temp2; B[2][2] = temp3;

	}
}

void r(int r)
{
	int i, j, k;
	char temp1, temp2, temp3;

	for (k = 0; k < r; k++) {
		//해당 방향
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				temp[j][2 - i] = R[i][j];
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				R[i][j] = temp[i][j];
		temp1 = D[0][2]; temp2 = D[1][2]; temp3 = D[2][2];
		D[0][2] = B[2][0]; D[1][2] = B[1][0]; D[2][2] = B[0][0];
		B[2][0] = U[0][2]; B[1][0] = U[1][2]; B[0][0] = U[2][2];
		U[0][2] = F[0][2]; U[1][2] = F[1][2]; U[2][2] = F[2][2];
		F[0][2] = temp1; F[1][2] = temp2; F[2][2] = temp3;
	}
}

void cube()
{
	int i, j, n, rot;
	char direction, rotate;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> direction >> rotate;
		if (rotate == '+')
			rot = 1;
		else
			rot = 3;

		if (direction == 'U')
			u(rot);
		else if (direction == 'D')
			d(rot);
		else if (direction == 'F')
			f(rot);
		else if (direction == 'B')
			b(rot);
		else if (direction == 'L')
			l(rot);
		else if (direction == 'R')
			r(rot);
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << U[i][j];
		}
		cout << "\n";
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, T;
	char test[3][3] = {{ '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' }};
	cin >> T;

	for (i = 0; i < T; i++) {
		init();
		cube();
	}
	return 0;
}
