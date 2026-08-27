#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

struct LCA {
    int n, lg;
    vector<int> depth, component;
    vector<vector<int>> up;

    static int levels(int n) {
        int result = 1;
        while ((1LL << result) <= n) ++result;
        return result;
    }
    explicit LCA(const vector<vector<int>>& tree)
        : n((int)tree.size()), lg(levels(n)), depth(n), component(n, -1),
          up(lg, vector<int>(n, -1)) {
            int root = 1; 
            component[root] = root;
            vector<int> stk{root};
            while (!stk.empty()) {
                int u = stk.back(); stk.pop_back();
                for (int v : tree[u]) if (v != up[0][u] && component[v] == -1) {
                    component[v] = root; depth[v] = depth[u] + 1; up[0][v] = u;
                    stk.push_back(v);
                }
            }
        for (int j = 1; j < lg; ++j)
            for (int i = 0; i < n; ++i)
                if (up[j - 1][i] != -1) up[j][i] = up[j - 1][up[j - 1][i]];
    }

    int jump(int u, int k) const {
        for (int j = 0; j < lg && u != -1; ++j) if (k >> j & 1) u = up[j][u];
        return u;
    }
    int lca(int u, int v) const {
        if (component[u] != component[v]) return -1;
        if (depth[u] < depth[v]) swap(u, v);
        u = jump(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int j = lg - 1; j >= 0; --j) if (up[j][u] != up[j][v]) {
            u = up[j][u]; v = up[j][v];
        }
        return up[0][u];
    }
    int distance(int u, int v) const {
        int w = lca(u, v);
        return w == -1 ? -1 : depth[u] + depth[v] - 2 * depth[w];
    }
};
bool f(int a, int b, int c, int d) {
    if (a * d - c * b >= 0) return 1;
    else return 0;
}
int qpow(int a, int b) {
    int rtn = 1;
    while (b) {
        if (b & 1) rtn = rtn * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return rtn;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LCA z(g);
    vector<int> node;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) node.push_back(i);
    }
    int len = node.size();
    int maxa = 0, maxb = 0;
    for (int i = 0; i < len; i++) {
        int u = node[i];
        int cura = 0, curb = 0;
        for (int j = 0; j < len; j++) {
            int v = node[j];
            if (u == v) continue;
            int a, b, c;
            a = z.lca(u, v);
            b = z.lca(u, 1);
            c = z.lca(v, 1);
            int md = max(max(z.depth[a], z.depth[b]), z.depth[c]);
            int m;
            if (z.depth[a] == md) m = a;
            if (z.depth[b] == md) m = b;
            if (z.depth[c] == md) m = c;
            int distab = z.depth[u] + z.depth[v] - 2 * z.depth[m];
            int distbm = z.depth[v] - z.depth[m];
            if (f(cura, curb, distbm, distab)) {
                cura = distbm;
                curb = distab;
            }
        }
        if (f(cura, curb, maxa, maxb)) {
            maxa = cura;
            maxb = curb;
        }
    }
    int ans = qpow(maxb, MOD - 2);
    ans = (ans * maxa) % MOD;
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}