#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxN = 1000000;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)

int a[maxN], n;

int main() {
    cin >> n;
    foru(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << a[(n + 1) / 2];
}
