#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    int d = gcd(n, k);
    vector <int> xr(d, 0);
    for (int i = 0; i < n; i++) {
        int r = i % d;
        xr[r] ^= a[i];
    }
    for (int i = 0; i < d; i++) {
        int j = (d - 1 - i) % d;
        if (i == j) {
            if (xr[i] != 0) return false;
        }
        else {
            if (xr[i] != xr[j]) return false;
        }
    }
    return true;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
    cin >> T;
	while(T--) {
		cout << (solve()? "YES" : "NO") << '\n';
	}
	return 0; 
}
// 110001
