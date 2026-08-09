#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int F[30005], siz[30005], d[30005];

int find (int x) {
	if (x == F[x]) return x;
	int y = find(F[x]);
	d[x] += d[F[x]];
	return F[x] = y;
}

void merge (int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	F[fx] = fy;
	d[fx] = siz[fy]; 
	siz[fy] += siz[fx];
}

void solve() {
	int q;
	cin >> q;
	for (int i = 1; i <= 30000; i++) {
		siz[i] = 1;
		F[i] = i;
	}
	while (q--) {
		char op;
		int x, y;
		cin >> op;
		if (op == 'M') {
			cin >> x >> y;
			merge(x, y);
		}
		else {
			cin >> x;
			find(x);
			cout << d[x] << '\n';
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while (T--) {
	    solve();
	}
	return 0; 
}