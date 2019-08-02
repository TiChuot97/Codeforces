#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

const int maxN = 4e5 + 10;

int a[maxN], m, n, res;
map < int, int > mmap;

void remove(int x) {
    if (--mmap[x] == 0) mmap.erase(x);
}

int csize() {
    return n * ceil(log2(1.0l * mmap.size()));
}

bool dnf() {
    return csize() > m;
}

int main() {
    cin >> n >> m; m *= 8;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    int j = 0;
    res = n;
    for (int i = 0; i < n; ++i) {
        ++mmap[a[i]];
        while (j < i && dnf()) remove(a[j++]);
        if (!dnf())
            res = min(res, n - (i - j + 1));
    }
    cout << res << endl;
}
