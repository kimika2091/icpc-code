#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int F[50005], r[50005];

int find (int x) {
	if (x == F[x]) return x;
	int y = find(F[x]);
	r[x] = (r[x] + r[F[x]]) % 3;
	return F[x] = y;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	iota(F, F + 1 + n, 0);
	while (k--) {
		int op, x, y;
		cin >> op >> x >> y;
		if (x > n || y > n) {
			ans++;
			continue;
		}
		if (op == 1) {
			int fx = find(x), fy = find(y);
			if (fx == fy) {
				if (r[x] != r[y]) {
					ans++;
				}
			}
			else {
				F[fy] = fx;
				r[fy] = (r[x] - r[y] + 3) % 3;
			}
		}
		else {
			if (x == y) {
				ans++;
				continue;
			}
			int fx = find(x), fy = find(y);
			if (fx == fy) {
				if ((r[x] - r[y] + 3) % 3 != 1) {
					ans++;
					continue;
				}
			}
			else {
				F[fy] = fx;
				r[fy] = (r[x] - r[y] + 2) % 3;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}

// r[x] : 0 (x=F[x]) 1(x<-F[x]) 2(x->F[x])