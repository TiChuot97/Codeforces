#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)

char c;
int d;

int main() {
    cin >> c >> d;
    int res = 8;
    if (c == 'a' || c == 'h') res -= 3;
    if (d == 1 || d == 8) res -= 3;
    if (res == 2) ++res;
    cout << res;
}
