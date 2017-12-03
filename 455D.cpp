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

const int maxN = 1e5 + 10, maxS = 350;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < ll, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

int n, nq, a[maxN], bsize, c[maxS][maxN], res;
deque < int > q[maxS];

int get_block(int i) { return ((i - 1) / bsize) + 1; }
int get_pos(int i) { return ((i - 1) % bsize); }

void print() {
    FORU(i, 1, get_block(n)) {
        printf("%d: ", i);
        REPU(j, q[i].size()) printf("%d ", q[i][j]);
        cout << endl;
    }
}


void build() {
    bsize = (int) sqrt(n);
    FORU(i, 1, n) {
        auto b = get_block(i);
        q[b].push_back(a[i]);
        ++c[b][a[i]];
    }
}

void update(int l, int r) {
    auto block_l = get_block(l);
    auto block_r = get_block(r);
    if (block_r == block_l) {
        auto tmp = q[block_l][get_pos(r)];
        q[block_l].erase(q[block_l].begin() + get_pos(r));
        q[block_l].insert(q[block_l].begin() + get_pos(l), tmp);
        return;
    }
    auto tmp = q[block_l].back();
    q[block_l].pop_back();
    q[block_l].insert(q[block_l].begin() + get_pos(l), q[block_r][get_pos(r)]);
    ++c[block_l][q[block_r][get_pos(r)]];
    --c[block_l][tmp];

    FORU(i, block_l + 1, block_r - 1) {
        q[i].push_front(tmp);
        ++c[i][tmp];
        tmp = q[i].back();
        --c[i][tmp];
        q[i].pop_back();
    }

    --c[block_r][q[block_r][get_pos(r)]];
    q[block_r].erase(q[block_r].begin() + get_pos(r));
    q[block_r].push_front(tmp);
    ++c[block_r][tmp];
}

int get(int l, int r, int k) {
    auto block_l = get_block(l);
    auto block_r = get_block(r);
    if (block_r == block_l) {
        auto ans = 0;
        FORU(i, get_pos(l), get_pos(r)) ans += (q[block_l][i] == k);
        return ans;
    }
    auto ans = 0;
    FORU(i, get_pos(l), q[block_l].size() - 1) ans += (q[block_l][i] == k);
    FORU(i, block_l + 1, block_r - 1) ans += c[i][k];
    REPU(i, get_pos(r) + 1) ans += (q[block_r][i] == k);
    return ans;
}

int main() {
    cin >> n;
    FORU(i, 1, n) scanf("%d", &a[i]);
    build();
    cin >> nq;
    FORU(i, 1, nq) {
        int t, l, r, k;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d", &l, &r);
            l = ((res + l - 1) % n) + 1;
            r = ((res + r - 1) % n) + 1;
            if (l > r) swap(l, r);
            update(l, r);
        }
        else {
            scanf("%d %d %d", &l, &r, &k);
            l = ((res + l - 1) % n) + 1;
            r = ((res + r - 1) % n) + 1;
            k = ((res + k - 1) % n) + 1;
            if (l > r) swap(l, r);
            res = get(l, r, k);
            printf("%d\n", res);
        }
    }
}
