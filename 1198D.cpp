#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 55;

int a[maxN][maxN], f[maxN][maxN][maxN][maxN], m, n;
char s[maxN];

int dp(int x1, int y1, int x2, int y2) {
    if (x1 == x2 - 1 && y1 == y2 - 1) return a[x1][y1];
    int& F = f[x1][y1][x2][y2];
    if (F != -1) return F;
    F = max(x2 - x1, y2 - y1);
    for (int s = x1; s < x2; ++s)
        F = min(F, dp(x1, y1, s + 1, y2) + dp(s + 1, y1, x2, y2));
    for (int s = y1; s < y2; ++s)
        F = min(F, dp(x1, y1, x2, s + 1) + dp(x1, s + 1, x2, y2));
    return F;
}

int main() {
    cin >> n; m = n;
    for (int i = 0; i < m; ++i) {
        scanf("%s\n", s);
        for (int j = 0; j < n; ++j) a[i][j] = (s[j] == '#');
    }
    memset(f, 255, sizeof(f));
    cout << dp(0, 0, m, n) << endl;
}
