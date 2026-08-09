#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int F[500005], siz[500005], mx[500005], w[250005];

int find (int x) {
    if (F[x] == x) return x;
    int y = find(F[x]);
    mx[x] = max(mx[x], mx[F[x]]);
    return F[x] = y;
}

int rt;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    int l = 0;

    auto id = [&](int x, int y) -> int {
        return (x - 1) * m + y;
    };
    
    rt = n * m;
    iota(F, F + 2 * rt, 0);
    fill(siz, siz + 2 * rt, 1);

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        x ^= l, y ^= l;
        int cur = id(x, y);
        if (op == 1) {
            cin >> w[cur];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                int nxt = id(nx, ny);
                if (w[nxt]) {
                    int fu = find(cur), fv = find(nxt);
                    if (fu != fv) {
                        rt++;
                        F[fu] = F[fv] = rt;
                        siz[rt] = siz[fu] + siz[fv];
                        mx[fu] = w[cur] - siz[fu] + 1;
                        mx[fv] = w[cur] - siz[fv] + 1;
                    }
                }
            }
            l = siz[find(cur)] - 1;
        }
        else {
            find(cur);
            l = max(0, mx[cur] - w[cur]);
        }
        cout << l << '\n';
    }
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}
	return 0; 
}