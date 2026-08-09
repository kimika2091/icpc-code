#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector <ll> a(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        cin >> a[i];
    }
    if (n == 1){
        cout << a[2] - a[1] << '\n';
        return;
    }
    vector <vector<ll>> pre(n + 2, vector<ll>(4, -inf));
    pre[2][0] = -a[1] - a[2];
    pre[0][1] = -a[1] + a[2];
    for (int i = 3; i <= n; i++) {
        vector <vector<ll>> cur(n + 2, vector<ll>(4, -inf));
        for (int j = 0; j <= i - 1; j++) {
            for (int k = 0; k < 4; k++) {
                if (pre[j][k] == -inf) continue;
                int k1 = k & 1;
                int k2 = (k >> 1) & 1;
                bool f = 0;
                if (k1 == 0 && k2 == 0 && a[i - 1] >= a[i - 2]) {
                    f = 1;
                }
                vector <int> b;
                if (f) {
                    b.push_back(0);
                } 
                else {
                    b.push_back(0);
                    b.push_back(1);
                }
                for (int op : b) {
                    if (op == 1 && j < 1) continue;
                    int j1;
                    ll nxt;
                    if (op == 0) {
                        j1 = j + 1;
                        nxt = pre[j][k] - a[i];
                    }
                    else {
                        j1 = j - 1;
                        nxt = pre[j][k] + a[i];
                    }

                    int now = (k1 << 1) | op;
                    if (nxt > cur[j1][now]) {
                        cur[j1][now] = nxt;
                    }
                }
            }
        }
        pre = move(cur);
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (pre[i][j] == -inf) continue;
            ll tot = pre[i][j] + 1ll * i * a[n + 1];
            ans = max(ans, tot);
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