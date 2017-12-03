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

const int maxN = 2e5 + 10, oo = 2e9 + 1;

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

int a[maxN], n;

LL min_xor(int l1, int r1, int l2, int r2, int b) {
    if (r1 < l1) return oo;
    if (r2 < l2) return oo;
    if (b < 0) return 0;
    int mid1 = l1, mid2 = l2;
    while (mid1 <= r1 && BIT(a[mid1], b) == 0) ++mid1;
    while (mid2 <= r2 && BIT(a[mid2], b) == 0) ++mid2;
    if ((l1 <= mid1 - 1 && l2 <= mid2 - 1) ||
        (mid1 <= r1 && mid2 <= r2))
        return min(
                min_xor(l1, mid1 - 1, l2, mid2 - 1, b - 1),
                min_xor(mid1, r1, mid2, r2, b - 1));
    return min(
            min_xor(l1, mid1 - 1, mid2, r2, b - 1) + (1 << b),
            min_xor(mid1, r1, l2, mid2 - 1, b - 1) + (1 << b));
}

LL kruskal(int l, int r, int b) {
    if (b < 0 || l >= r) return 0;
    int mid = l;
    while (mid <= r && BIT(a[mid], b) == 0) ++mid;
    LL edge = (l <= mid - 1 && mid <= r) ? min_xor(l, mid - 1, mid, r, b) : 0;
    return 
        kruskal(l, mid - 1, b - 1) + 
        kruskal(mid, r, b - 1) + 
        edge;
}

int main() {
    cin >> n;
    FORU(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    cout << kruskal(1, n, 29) << endl;
}
