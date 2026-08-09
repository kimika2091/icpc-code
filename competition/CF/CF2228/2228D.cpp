#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e6 + 5;

int head_x[MAXN], nxt[MAXN], p_y[MAXN];
bool has_y[MAXN];
int y_rank[MAXN];
int minidx[MAXN], maxidx[MAXN];
int pre_min[MAXN], pre_max[MAXN];
int suf_min[MAXN], suf_max[MAXN];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {   
        head_x[i] = -1;
        has_y[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        nxt[i] = head_x[x];
        head_x[x] = i;
        p_y[i] = y;
        has_y[y] = true;
    }

    int h = 0;
    for (int i = 1; i <= n; ++i) {
        if (has_y[i]) {
            y_rank[i] = ++h;
        }
    }

    int m = 0;
    for (int x = 1; x <= n; ++x) {
        if (head_x[x] != -1) {
            m++;
            int curr_min = h + 1;
            int curr_max = 0;
            for (int e = head_x[x]; e != -1; e = nxt[e]) {
                int r = y_rank[p_y[e]];
                if (r < curr_min) curr_min = r;
                if (r > curr_max) curr_max = r;
            }
            minidx[m] = curr_min;
            maxidx[m] = curr_max;
        }
    }

    if (m < 2 || h < 2) {
        cout << 0 << "\n";
        return;
    }

    pre_min[0] = h + 1;
    pre_max[0] = 0;
    for (int i = 1; i <= m; ++i) {
        pre_min[i] = min(pre_min[i - 1], minidx[i]);
        pre_max[i] = max(pre_max[i - 1], maxidx[i]);
    }

    suf_min[m + 1] = h + 1;
    suf_max[m + 1] = 0;
    for (int i = m; i >= 1; --i) {
        suf_min[i] = min(suf_min[i + 1], minidx[i]);
        suf_max[i] = max(suf_max[i + 1], maxidx[i]);
    }

    ll ans = 0;
    for (int i = 1; i < m; ++i) {
        int mn = max(pre_min[i], suf_min[i + 1]);
        int mx = min(pre_max[i], suf_max[i + 1]);
        if (mx > mn) {
            ans += (mx - mn);
        }
    }

    cout << ans << "\n";
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}