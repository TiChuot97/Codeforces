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

const int maxN = 200010, maxL = 10010, oo = 1000000000;
const double PI = acos(-1);

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pint pair < ll, int >

int n, d[maxN], a[maxN];

int main() {
    cin >> n;
    foru(i, 1, n) scanf("%d", &a[i]), d[i] = oo;
    int pos = 0;
    foru(i, 1, n) {
        if (a[i] == 0) pos = i;
        if (pos) d[i] = min(d[i], (int) abs(i - pos));
    }
    pos = 0;
    ford(i, n, 1) {
        if (a[i] == 0) pos = i;
        if (pos) d[i] = min(d[i], (int) abs(i - pos));
    }
    foru(i, 1, n) printf("%d ", d[i]);
}
