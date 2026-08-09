#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500010];

void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout <<"1"<<endl;
        return;
    }
    if(n & 1) {
        int num = 0, A = n, B = 2;
        a[++num] = (n-1)/2 + 1;
        while(num < n-2) {
            a[++num] = A;
            a[++num] = B;
            A--, B++;
        }
        a[n-1] = 1, a[n] = (n-1)/2+2;
        for(int i = 1; i <= n; i++) {
            int pos = (n-1+i-1);
            if(pos > n) pos = (pos%n);
            cout << a[pos]<< " ";
        }
        cout << endl;
    }
    else {
        int A = n, B = 2, num = 0;
        while(num < n - 2) {
            a[++num] = A;
            a[++num] = B;
            A--, B++;
        }
        a[n-1] = 1, a[n] = (n-1)/2 + 2;
        for(int i = 1; i <= n; i++) {
            int pos = (n-1+i-1);
            if(pos > n) pos = (pos%n);
            cout << a[pos]<< " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
