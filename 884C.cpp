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

const int maxN = 1e5 + 10, oo = 23041997;
const double eps = 1e-5;

using namespace std;

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

int n, a[maxN], check[maxN];
LL res;

int main() {
    cin >> n;
    FORU(i, 1, n) scanf("%d", &a[i]);
    int max1 = 0, max2 = 0;
    FORU(i, 1, n)
        if (!check[i]) {
            int j = i, c = 0;
            while (!check[j]) {
                check[j] = 1;
                j = a[j];
                ++c;
            }
            res += 1ll * c * c;
            if (c > max1) max2 = max1, max1 = c;
            else max2 = max(max2, c);
        }
    res += 2ll * max1 * max2;
    cout << res << endl;
}
