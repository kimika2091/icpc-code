#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge{
    int u, v, w;
};
bool cmp1 (const Edge &a, const Edge &b) { return a.w > b.w; }
bool cmp2 (const Edge &a, const Edge &b) { return a.w < b.w; }

vector <int> fa;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]);}
void init(int n) {
    fa.assign(n + 1, 0);
    iota(fa.begin(), fa.end(), 0);
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> a(m + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    auto kruskal = [&]() -> int {
        init(n);
        int cnt = 0, tot_b = 0;
        for (auto [u, v, w] : a) {
            int fu = find(u), fv = find(v);
            if (fu == fv) continue;
            fa[fu] = fv;
            if (w == 0) tot_b++;
            cnt++;
            if (cnt == n - 1) {
                return tot_b;
            }
        }
        return -1;
    };
    sort(a.begin(), a.end(), cmp1);
    int L = kruskal();
    sort(a.begin(), a.end(), cmp2);
    int R = kruskal();
    if (L == -1 || R == -1) cout << 0 << '\n';
    else {
        cout << R - L + 1 << '\n';
    }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
