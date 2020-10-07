//토너먼트 경기 - 같은 시드에서 만날때 까지..
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int i, N = 0, mod;

    while (n > 1) {
        n /= 2;
        ++N;
    }
    for (i = 1; i <= N; i++) {
        mod = pow(2, i);
        if ((a % mod ? (a / mod) + 1 : a / mod) == (b % mod ? (b / mod) + 1 : b / mod)) break;
    }
    return i;
}
