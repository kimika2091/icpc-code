#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Edge {
    int to, rev, cap;
    ll cost;
};

struct MinCostFlow {
    vector<vector<Edge>> g;

    MinCostFlow(int n) : g(n) {}

    void addEdge(int u, int v, int cap, ll cost) {
        Edge a{v, (int)g[v].size(), cap, cost};
        Edge b{u, (int)g[u].size(), 0, -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    ll flow(int s, int t, int need) {
        const ll INF = (1LL << 62);
        int n = g.size();
        vector<ll> dis(n), pot(n);
        vector<int> pv(n), pe(n);
        ll ans = 0;

        while (need) {
            fill(dis.begin(), dis.end(), INF);
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
            dis[s] = 0;
            q.push({0, s});

            while (!q.empty()) {
                auto [d, u] = q.top();
                q.pop();
                if (d != dis[u]) continue;
                for (int i = 0; i < (int)g[u].size(); ++i) {
                    Edge &e = g[u][i];
                    if (!e.cap) continue;
                    ll nd = d + e.cost + pot[u] - pot[e.to];
                    if (nd < dis[e.to]) {
                        dis[e.to] = nd;
                        pv[e.to] = u;
                        pe[e.to] = i;
                        q.push({nd, e.to});
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                if (dis[i] != INF) pot[i] += dis[i];
            }

            int add = need;
            for (int v = t; v != s; v = pv[v]) add = min(add, g[pv[v]][pe[v]].cap);
            need -= add;
            ans += 1LL * add * pot[t];
            for (int v = t; v != s; v = pv[v]) {
                Edge &e = g[pv[v]][pe[v]];
                e.cap -= add;
                g[v][e.rev].cap += add;
            }
        }
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int s = n + m, t = s + 1;
    MinCostFlow mf(t + 1);

    for (int i = 0; i < n; ++i) {
        mf.addEdge(s, i, 1, 0);
        int x;
        cin >> x;
        while (x--) {
            int v;
            cin >> v;
            mf.addEdge(i, n + v - 1, 1, 0);
        }
    }

    for (int i = 0; i < m; ++i) {
        int y;
        cin >> y;
        for (int j = 0; j < y; ++j) {
            ll w;
            cin >> w;
            mf.addEdge(n + i, t, 1, w);
        }
    }

    cout << mf.flow(s, t, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
