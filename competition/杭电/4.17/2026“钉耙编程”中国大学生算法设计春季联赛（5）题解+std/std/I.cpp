#include <bits/stdc++.h>
using namespace std;

#define ll long long

mt19937 rng(998244353);

const int TRIALS = 500;
const int N = 10007;
const int K = 6;
const ll INF = 1e18;

int n, m, k;
int a[N], c[N];
vector<pair<int, int>> g[N];

ll f[N][K];
ll e[N][K][2];

void sc() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
    }
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--; u--;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }

    for (int v = 0; v < n; v++) {
        sort(g[v].begin(), g[v].end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
    }

    ll ans = INF;
    for (int _ = 0; _ < TRIALS; _++) {
        for (int v = 0; v < n; v++) {
            c[v] = rng() & 1;
            for (int x = 0; x < k; x++) {
                f[v][x] = INF;
                e[v][x][0] = e[v][x][1] = INF;
            }
        }
        for (int v = 0; v < n; v++) {
            for (auto [u, w] : g[v]) {
                if (c[u] != c[v]) continue;
                for (int j = 0; j < 2; j++) {
                    if (e[v][a[u]][j] == INF) {
                        e[v][a[u]][j] = w;
                        break;
                    }
                }
            }
        }
        for (int v = 0; v < n; v++) {
            f[v][a[v]] = 0;
            for (auto [u, w] : g[v]) {
                if (c[v] != c[u]) continue;
                int s = (a[v] + a[u]) % k;
                f[v][s] = min(f[v][s], (ll)w);
                for (int x = 0; x < k; x++) {
                    int ss = (s + x) % k;
                    f[v][ss] = min(f[v][ss], (e[u][x][0] == w ? e[u][x][1] : e[u][x][0]) + w);
                }
            }
        }
        for (int v = 0; v < n; v++) {
            ans = min(ans, f[v][0]);
            if (c[v]) continue;
            for (auto [u, w] : g[v]) {
                if (!c[u]) continue;
                for (int x = 1; x < k; x++) {
                    ans = min(ans, f[v][x] + f[u][k - x] + w);
                }
            }
        }
    }

    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) sc();
    return 0;
}
