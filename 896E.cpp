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

const int maxN = 1e5 + 10, maxB = 400;

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

int cnt[maxB][maxN], parent[maxB][maxN], a[maxN], n, q, res, offset[maxB], block_size, max_val[maxB];

int get_block(int i) {
    return i / block_size;
}

int get_left_endpoint(int b) {
    return block_size * b;
}

int get_right_endpoint(int b) {
    return min(block_size * (b + 1) - 1, n - 1);
}

void build_blocks() {
    block_size = (int) sqrt(n);
    REPU(i, n) {
        int b = get_block(i);
        ++cnt[b][a[i]];
        max_val[b] = 1e5;
    }
}

int get_root(int b, int x) {
    int& p = parent[b][x];
    return (p == x || p == 0) ? (p = x) : (p = get_root(b, p));
}

void update_element(int l, int r, int x) {
    int b = get_block(l);
    FORU(i, l, r) {
        a[i] = get_root(b, a[i]);
        if (a[i] > x + offset[b]) {
            --cnt[b][a[i]];
            a[i] -= x;
            ++cnt[b][a[i]];
        }
    }
}

void update_block(int l, int r, int x) {
    FORU(b, l, r) {
        if (offset[b] + x >= max_val[b]) continue;
        if (max_val[b] >= 2 * x + offset[b]) {
            FORU(v, offset[b] + 1, offset[b] + x) {
                parent[b][v] = v + x;
                cnt[b][v + x] += cnt[b][v];
                cnt[b][v] = 0;
            }
            offset[b] += x;
        }
        else {
            FORU(v, x + offset[b] + 1, max_val[b]) {
                parent[b][v] = v - x;
                cnt[b][v - x] += cnt[b][v];
                cnt[b][v] = 0;
            }
            max_val[b] = offset[b] + x;
        }
    }
}

void query_element(int l, int r, int x) {
    int b = get_block(l);
    FORU(i, l, r) {
        a[i] = get_root(b, a[i]);
        if (a[i] == x + offset[b]) ++res;
    }
}

void query_block(int l, int r, int x) {
    FORU(b, l, r)
        if (x + offset[b] <= max_val[b])
            res += cnt[b][x + offset[b]];
}

int main() {
    cin >> n >> q;
    REPU(i, n) scanf("%d", &a[i]);

    build_blocks();

    FORU(i, 1, q) {
        int t, l, r, x;
        scanf("%d %d %d %d", &t, &l, &r, &x);
        --l; --r;
        int L = get_block(l);
        int R = get_block(r);
        if (L == R) {
            if (t == 1) update_element(l, r, x);
            else {
                res = 0;
                query_element(l, r, x);
                cout << res << endl;
            }
        }
        else {
            if (t == 1) {
                update_block(L + 1, R - 1, x);
                update_element(l, get_right_endpoint(L), x);
                update_element(get_left_endpoint(R), r, x);
            }
            else {
                res = 0;
                query_block(L + 1, R - 1, x);
                query_element(l, get_right_endpoint(L), x);
                query_element(get_left_endpoint(R), r, x);
                cout << res << endl;
            }
        }
    }
}
