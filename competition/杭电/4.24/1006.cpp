#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dis[405][405][405];
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <vector<pair<int,int>>> e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        char c;
        cin >> u >> v >> c;
        w = c == '(' ? 1 : -1;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    auto bfs = [&](int s) -> void {
        for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) dis[s][i][j] = 1e9; 
        queue <pair<int, int>> q;
        dis[s][s][0] = 0;
        q.push({s, 0});
        while (!q.empty()) {
            auto [u, now] = q.front();
            q.pop();
            for (auto [v, w] : e[u]) {
                if (now + w > n || now + w < 0) continue;
                if (dis[s][v][now + w] > dis[s][u][now] + 1) {
                    dis[s][v][now + w] = dis[s][u][now] + 1;
                    q.push({v, now + w});
                }
            }
        }
    };
    for (int i = 1; i <= n; i++) bfs(i);
    while(q--) {
        int x, y;
        cin >> x >> y;
        if (dis[x][y][0] == 1e9) dis[x][y][0] = -1; 
        cout << dis[x][y][0] << '\n'; 
    }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}
