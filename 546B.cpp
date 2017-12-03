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

const int maxN = 3e3;

using namespace std;

int n, res, a[maxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);

    for (int i = 1; i < n; ++i)
        if (a[i] <= a[i - 1]) {
            res += (a[i - 1] + 1 - a[i]);
            a[i] = a[i - 1] + 1;
        }

    cout << res;
}
