#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    int c2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] >= 2) {
            c2++;
        }
    }
    
    if (c2 == 0) {
        cout << 0 << "\n";
        return;
    }
    
    if (c2 == 1) {
        int ans = c[n - 1] + min((int)(n - 1), c[n - 1] / 2);
        if (ans < 3) {
            cout << 0 << "\n";
        } else {
            cout << ans << "\n";
        }
        return;
    }
    
    int sum = 0;
    int t = 0;
    for (int i = n - c2; i < n; ++i) {
        sum += c[i];
        t += (c[i] / 2 - 1);
    }
	
    int ans = sum + min(n - c2, t);
    if (ans < 3) {
        cout << 0 << "\n";
    } else {
        cout << ans << "\n";
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

