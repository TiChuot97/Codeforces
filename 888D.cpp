#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <stack>

using namespace std;

const int maxN = 1e3 + 10;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define ULL unsigned long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < int, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

LL c[maxN][maxN], p[maxN], res;
int n, k;

void init() {
    FORU(i, 0, n) c[i][0] = 1;
    FORU(i, 1, n)
        FORU(j, 1, i)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    p[0] = 1;
    FORU(i, 1, k) p[i] = p[i - 1] * i;
}

LL perm(int n, int k) {
    LL tmp = 0;
    FORU(i, 0, k) {
        if (i % 2)
            tmp -= c[k][i] * p[k - i];
        else
            tmp += c[k][i] * p[k - i];
    }
    return c[n][k] * tmp;
}

int main() {
    cin >> n >> k;
    init();
    REPU(i, k + 1)
        res += perm(n, k - i);
    cout << res;
}
