#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int F[30005], d[30005], siz[30005];

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
void query (int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) {
		cout << -1 << '\n';
		return;
	}
	if (d[x] > d[y]) cout << d[x] - d[y] - 1 << '\n';
	else cout << d[y] - d[x] - 1 << '\n';
}

void solve() {
	int q;
	cin >> q;
	
	for (int i = 1; i <= 30000; i++) {
		F[i] = i;
		siz[i] = 1;
	}

	while (q--) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'M') {
			merge(x, y);
		}
		else {
			query(x, y);
		}
	}
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