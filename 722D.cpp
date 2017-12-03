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

using namespace std;

const int oo = 23041997, maxN = 1e6, maxM = 20;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < int, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

int res[maxN], b[maxN][maxM], a[maxN], n, check[maxN];

bool cmp(int i, int j) {
    FORU(t, 1, min(b[i][0], b[j][0])) {
        if (b[i][t] > b[j][t]) return true;
        if (b[i][t] < b[j][t]) return false;
    }
    return b[i][0] < b[j][0];
}

void binary(int i, int x) {
    while (x) b[i][++b[i][0]] = x % 2, x /= 2;
    reverse(b[i] + 1, b[i] + b[i][0] + 1);
}

int main() {
    cin >> n;
    FORU(i, 1, n) {
        int x;
        scanf("%d", &x);
        binary(i, x);
    }
    FORU(i, 1, n) a[i] = i;
    sort(a + 1, a + n + 1, cmp);
    FORU(i, 1, n) {
        FORU(j, 1, b[a[i]][0]) printf("%d", b[a[i]][j]);
        cout << endl;
    }
    FORU(i, 1, n) {
        int x = 0;
        FORU(j, 1, b[a[i]][0]) {
            x = (x << 1) + b[a[i]][j];
            if (!check[x]) {
                res[i] = x;
                check[x] = 1;
                break;
            }
        }
    }
    FORU(i, 1, n) printf("%d ", res[i]);
}
