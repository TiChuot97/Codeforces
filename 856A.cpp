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

const int maxN = 1e6 + 10;

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

int a[maxN], b[maxN], check[maxN], n, test, flag;

int main() {
    cin >> test;
    while (test--) {
        cin >> n; ++flag;
        FORU(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        FORU(i, 1, n) {
            b[i] = b[i - 1] + 1;
            while (check[b[i]] == flag) ++b[i];
            FORU(j, 1, n)
                FORU(t, j + 1, n)
                    if (b[i] + a[t] - a[j] <= 1e6)
                        check[b[i] + a[t] - a[j]] = flag;
        }
        cout << "YES" << endl;
        FORU(i, 1, n)
            printf("%d ", b[i]);
        cout << endl;
    }
}
