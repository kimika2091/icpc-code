#include <bits/stdc++.h>
using namespace std;

struct SCC {
    int n, timer = 0, count = 0;
    const vector<vector<int>>& g;
    vector<int> dfn, low, comp, stk;
    vector<char> inStack;

    explicit SCC(const vector<vector<int>>& graph)
        : n((int)graph.size()), g(graph), dfn(n), low(n), comp(n, -1), inStack(n) {
        for (int i = 0; i < n; ++i) if (!dfn[i]) dfs(i);
    }

    void dfs(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u); inStack[u] = true;
        for (int v : g[u]) {
            if (!dfn[v]) dfs(v), low[u] = min(low[u], low[v]);
            else if (inStack[v]) low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            while (true) {
                int v = stk.back(); stk.pop_back(); inStack[v] = false;
                comp[v] = count;
                if (v == u) break;
            }
            ++count;
        }
    }
};

struct DSU {
    vector<int> parent, size;
    explicit DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x; size[x] += size[y];
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int componentSize(int x) { return size[find(x)]; }
};

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector <vector<bool>> mp(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            mp[i][j] = ch == '.' ? 1 : 0;
        }
    }
    auto id = [&](int x, int y) -> int {
        return (x - 1) * m + y - 1;
    };
    DSU dsu(n * m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!mp[i][j]) continue;
            if (mp[i + 1][j]) dsu.merge(id(i, j), id(i + 1, j));
            if (mp[i - 1][j]) dsu.merge(id(i, j), id(i - 1, j));
            if (mp[i][j + 1]) dsu.merge(id(i, j), id(i, j + 1));
            if (mp[i][j - 1]) dsu.merge(id(i, j), id(i, j - 1));
        }
    }
    map <int, int> num;
    int o = 0;
    vector <vector<int>> g(2 * k);
    for (int i = 1; i <= k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x = dsu.find(id(x1, y1));
        int y = dsu.find(id(x2, y2));
        if (!num.count(x)) num[x] = o++;
        if (!num.count(y)) num[y] = o++;
        g[num[x]].push_back(num[y]);
    }
    SCC scc(g);
    vector <vector<int>> dag(scc.count);
    for (int i = 0; i < o; i++) {
        int x = scc.comp[i];
        for (auto &j : g[i]) {
            int y = scc.comp[j];
            if (x != y) dag[x].push_back(y);
        }
    }
    vector <vector<bool>> link(scc.count, vector<bool>(scc.count));
    auto bfs = [&](int s) -> void {
        queue <int> q;
        q.push(s);
        link[s][s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v : dag[u]) {
                if (link[s][v]) continue;
                q.push(v);
                link[s][v] = 1;
            }
        }
    };
    for (int i = 0; i < scc.count; i++) bfs(i);
    for (int i = 1; i <= q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x = dsu.find(id(x1, y1));
        int y = dsu.find(id(x2, y2));
        if (x == y) cout << 1 << '\n';
        else {
            if (!num.count(x) || !num.count(y)) cout << "0" << '\n';
            else {
                int c1 = scc.comp[num[x]], c2 = scc.comp[num[y]];
                cout << (link[c1][c2] ? 1 : 0) << '\n';
            }
        }
    }
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}