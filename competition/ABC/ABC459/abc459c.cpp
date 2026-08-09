#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
struct BIT {
    int n;
    vector<T> c;
    BIT(int n) : n(n), c(n + 1, 0) {}
    void add(int x, const T &v) {
		x++;
        for (; x <= n; x += x & -x)
            c[x] = c[x] + v;
    }
    T sum(int x) {
        T ans{};
		x++;
        for (; x > 0; x -= x & -x)
            ans = ans + c[x];
        return ans;
    }
};

void solve() {
	int n, q;
	cin >> n >> q;
	BIT<int> tr(1e6 + 5);
	vector <int> cnt(1e6 + 5, 0);
	int tot = 0;
	tr.add(0, n);
	for (int i = 1; i <= q; i++) {
		int opt, x;
		cin >> opt >> x;
		if (opt == 1) {
			tr.add(cnt[x], -1);
			cnt[x]++;
			tr.add(cnt[x], 1);
			if (tr.sum(tot) == 0) tot++;
		}
		else {
			cout << n - tr.sum(x + tot - 1) << '\n'; 
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