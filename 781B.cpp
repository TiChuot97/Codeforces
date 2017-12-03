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

const int maxN = 2000;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second
#define mp make_pair

int n, s[maxN], res[maxN], change[maxN], a[maxN];
char s1[maxN], s2[maxN], fn[maxN][4], sn[maxN][4];
map < string, int > mmap;

bool cmp(int i, int j) {
    int t = strcmp(fn[i], fn[j]);
    return (t < 0 || (t == 0 && strcmp(sn[i], sn[j]) < 0));
}

bool find_change(int u) {
    if (change[u] == 0) return false;
    string s = (res[u] == 0) ? fn[u] : sn[u];
    if (mmap[s])
        if (!find_change(mmap[s])) return false;
    mmap[s] = u;
    res[u] = 1 - res[u];
    return true;
}

int main() {
    scanf("%d\n", &n);
    foru(i, 1, n) {
        scanf("%s %s\n", s1, s2);
        foru(j, 0, 2) fn[i][j] = s1[j];
        foru(j, 0, 1) sn[i][j] = s1[j];
        sn[i][2] = s2[0];
        fn[i][3] = sn[i][3] = '\0';
        a[i] = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int l = 1, r = 1;
    while (l <= n) {
        while (r < n && strcmp(fn[a[l]], fn[a[r + 1]]) == 0) ++r;
        if (l == r) {
            res[a[l]] = 1;
            change[a[l]] = 1;
            string s = fn[a[l]];
            if (mmap[s])
                if (!find_change(a[l])) { cout << "NO"; return 0; }
            mmap[s] = a[l];
        }
        else 
            foru(i, l, r) {
                change[a[i]] = 0;
                string s = sn[a[i]];
                if (mmap[s])
                    if (!find_change(mmap[s])) { cout << "NO"; return 0; }
                mmap[s] = a[i];
            }
        l = r = r + 1;
    }
    cout << "YES" << endl;
    foru(i, 1, n)
        if (res[i]) printf("%s\n", fn[i]);
        else printf("%s\n", sn[i]);
}
