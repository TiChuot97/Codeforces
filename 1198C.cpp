#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxN = 3e5 + 10;

vector < pair < int, int > > adj[maxN];
vector < int > match;
set < int > iset;
int n, m, test;

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> m;
        int N = 3 * n;
        for (int i = 1; i <= N; ++i) adj[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v; scanf("%d %d", &u, &v);
            adj[u].push_back({v, i + 1});
            adj[v].push_back({u, i + 1});
        }
        match.clear();
        iset.clear();
        iset.insert(1);
        for (int u = 2; u <= N; ++u) {
            if (iset.size() == n || match.size() == n) break;
            bool ok = true;
            for (auto p : adj[u]) {
                int v = p.first;
                int w = p.second;
                if (iset.count(v)) {
                    iset.erase(v);
                    match.push_back(w);
                    ok = false;
                    break;
                }
            }
            if (ok) iset.insert(u);
        }
        if (iset.size() == n) {
            printf("IndSet\n");
            for (int u : iset) printf("%d ", u);
        } else {
            printf("Matching\n");
            for (int w : match) printf("%d ", w);
        }
        printf("\n");
    }
}
