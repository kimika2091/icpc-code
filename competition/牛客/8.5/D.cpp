#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector <vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <vector<int>> dis(n + 1, vector<int>(2, INF));
    queue <pair<int, int>> q;
    dis[1][0] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        auto [u, s] = q.front();
        q.pop();
        for (auto &v : g[u]) {
            if (dis[v][s ^ 1] == INF) {
                dis[v][s ^ 1] = dis[u][s] + 1;
                q.push({v, s ^ 1});
            }
        }
    }
    auto calc = [&](int x, int y) -> int {
        if (x == INF && y == INF) return -1;
        if (y == 0) return 0;
        if (k == 1) return min(x, y);
        if (k & 1) {
            if (x != INF) {
                int cnt = (x + k - 1) / k;
                if (!(cnt & 1)) cnt++;
                x = cnt * k;
            }
            if (y != INF) {
                int cnt = (y + k - 1) / k;
                if (cnt & 1) cnt++;
                y = cnt * k;
            }
            return min(x, y);
        }
        else {
            if (y == INF) return -1;
            return (y + k - 1) / k * k;
        }
    };
    for (int i = 1; i <= n; i++) {
        cout << calc(dis[i][1], dis[i][0]) << " \n"[i == n];
    }
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}