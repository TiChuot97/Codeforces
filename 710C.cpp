#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)

int n;

int main() {
    cin >> n;
    int a[2];
    int idx = 1;
    a[0] = 2;
    a[1] = 1;
    foru(i, 1, n) {
        foru(j, 1, n) {
            cout << a[idx] << " ";
            a[idx] += 2;
            idx = 1 - idx;
        }
        cout << endl;
    }
}
