#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector <ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector <vector<ll>> g(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((i + j) & 1) g[i][j] = g[j][i] = a[(i + j) / 2] + a[(i + j + 1) / 2];
            else g[i][j] = g[j][i] = a[(i + j) / 2] * 2;
        }
    }
    vector <ll> dist(n + 1, 1e18);
    dist[1] = 0;
    vector <bool> vis(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) 
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;
        vis[u] = 1;
        ans += dist[u];
        for (int v = 1; v <= n; v++) {
            if (!vis[v]) {
                dist[v] = min(dist[v], g[u][v]);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
    cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
