#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    stack<pair<int,int>> s;
    int lst = 0, cnt = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x == lst) {
            cnt++;
        }
        else {
            cnt = 1;
            lst = x; 
        }
        s.push({x, cnt});
        if (cnt == k) {
            while (cnt--) {
                s.pop();
            }
            if (!s.empty()) {
                lst = s.top().first;
                cnt = s.top().second;
            }
            else {
                lst = cnt = 0;
            }
        }
    }
    vector <int> p;
    while(!s.empty()) {
        p.push_back(s.top().first);
        assert(s.top().second < k);
        s.pop();
    }
    reverse(p.begin(),p.end());
    cout << p.size() << '\n';
    for (int i : p) cout << i << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
