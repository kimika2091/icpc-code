#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b;
    cin >> a >> b;
    int mn = min(a, b);
    if (mn > 1) cout << 1 << '\n';
    else if (mn == 1) {
        if (a == 1 && b == 1) cout << 2 << '\n';
        else {
            if (a == 2 || b == 2) cout << 3 << '\n';
            else {
                cout << 2 << '\n';
            }
        }
    }
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