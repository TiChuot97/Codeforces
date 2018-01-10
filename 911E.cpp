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

const int maxN = 2e5 + 10;

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

int a[maxN], res[maxN], n, k;

bool solve(int pos, int l, int r) {
    if (pos > n) return true;
    if (r < l) return true;
    res[pos] = (pos <= k) ? a[pos] : r;
    if (res[pos] < l || res[pos] > r) return false;
    if (!solve(pos + 1, l, res[pos] - 1)) 
        return false;
    if (!solve(pos + res[pos] - l + 1, res[pos] + 1, r))
        return false;
    return true;
}

int main() {
    cin >> n >> k;
    FORU(i, 1, k) scanf("%d", &a[i]);
    if (solve(1, 1, n))
        FORU(i, 1, n) printf("%d ", res[i]);
    else cout << -1;
}
