#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    if (n == 1) {
        cout << "NO\n";
        return;
    }

    int k = n / 2;
    vector<int> A(k + 1, 0);
    vector<int> B(k + 1, 0);

    int sumA = 0, sumB = 0;
    for (int i = 1; i <= k; ++i) {
        sumA += x[i - 1];
        A[i] = sumA;
        sumB += x[n - i];
        B[i] = sumB;
    }

    bool f = false;

    if (n % 2 != 0) { 
        f = false;
        for (int i = k; i >= 1; --i) {
            if (A[i] > B[i]) {
                f = true;
                break;
            } else if (A[i] < B[i]) {
                f = false;
                break;
            }
        }
    } else { 
        f = true; 
        for (int i = k; i >= 2; --i) {
            int a_val = A[i];
            int b_val = B[i - 1];
            if (a_val > b_val) {
                f = true;
                break;
            } else if (a_val < b_val) {
                f = false;
                break;
            }
        }
    }

    if (f) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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