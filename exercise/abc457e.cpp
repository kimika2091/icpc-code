#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Query{
	int id, l, r;
	bool operator < (const Query &other) const {
		return r < other.r;
	}
};

template <class T>
struct BIT {
    int n;
    vector<T> c;
    BIT(int n) : n(n), c(n + 1, 0) {}
    void add(int x, const T &v) {
        for (; x <= n; x += x & -x)
            c[x] = c[x] + v;
    }
    T sum(int x) {
        T ans{};
        for (; x > 0; x -= x & -x)
            ans = ans + c[x];
        return ans;
    }
    T sum(int x, int y) {
        return sum(y) - sum(x - 1);
    }
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector <Query> a(m + 1);
	vector <vector<int>> L(n + 1), R(n + 1);
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {i, x, y};
		R[x].push_back(y);
		L[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(L[i].begin(), L[i].end());
		sort(R[i].begin(), R[i].end());
	}
	int q;
	cin >> q;
	vector <Query> Q(q);
	for (int i = 0; i < q; i++) {
		int s, t;
		cin >> s >> t;
		Q[i] = {i, s, t};
	}
	sort(Q.begin(), Q.end());
	sort(a.begin(), a.end());
	BIT <int> tr(n + 2);
	vector <bool> ans(q);
	int p = 1;
	for (auto &[i, l, r] : Q) {
		while (p <= m && a[p].r <= r) tr.add(a[p].l, 1), p++;
		int cnt = tr.sum(l, r);
		int p1 = -1, p2 = -1;
		if (R[l].size()) {
			auto it = upper_bound(R[l].begin(), R[l].end(), r);
			if (it != R[l].begin()) it--, p1 = *it;
		}
		if (L[r].size()) {
			auto it = lower_bound(L[r].begin(), L[r].end(), l);
			if (it != L[r].end()) p2 = *it;
		}
		if (p1 == -1 || p2 == -1 || p1 < p2 - 1) {
			ans[i] = 0;
			continue;
		}
		if (p1 == r && p2 == l) {
			if (cnt >= 2) ans[i] = 1;
			else ans[i] = 0;
		}
		else ans[i] = 1;
	}
	for (bool i : ans) cout << (i ? "Yes" : "No") << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
