#include<bits/stdc++.h>
using namespace std;
#define int long long

struct LinearBasis {
    int n;
    vector<int> p;       
    LinearBasis(int n) : n(n), p(n + 1, 0) {}
    bool insert(int x) {
        for (int i = n; i >= 0; --i) {
            if (!(x >> i & 1))
                continue;
            if (!p[i]) {
                p[i] = x;
                return true;
            }
            x ^= p[i];
        }
        return false;
    }
    int query_max() {
        int res = 0;
        for (int i = n; i >= 0; --i) {
            res = max(res, res ^ p[i]);   
        }
        return res;
    }
};

void solve() {
	int n;
	cin >> n;
	vector <int> a(n + 1);
	LinearBasis L(31);
	int sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum ^= a[i];
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