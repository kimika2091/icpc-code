#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node{
    ll need, gain;
    int prev, next;
};

void solve() {
    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<Node> nodes(n);
    vector<bool> in(n);
    auto remove = [&](int cur) -> void{
        int prv = nodes[cur].prev, nxt = nodes[cur].next;
        nodes[prv].next = nxt;
        nodes[nxt].prev = prv;
        in[cur] = 0;
    };
    auto check = [&](ll x) -> bool {
        for (int i = 0; i < n; i++) {
            nodes[i].need = nodes[i].gain = s[i];
            nodes[i].prev = i == 0? n - 1 : i - 1;
            nodes[i].next = i == n - 1? 0 : i + 1;
            in[i] = 1;
        }
        int blocks = n;
        for (int i = 0; i < n && blocks > 1; i++) {
            if (!in[i] || x < nodes[i].need) continue;
            while (true) {
                bool ok = 0;
                int prv = nodes[i].prev, nxt = nodes[i].next;
                if (blocks > 1 && x + nodes[i].gain >= nodes[prv].need) {
                    ok = 1;
                    nodes[i].gain += nodes[prv].gain;
                    nodes[i].need = min(nodes[i].need, nodes[prv].need);
                    remove(prv);
                    blocks--;
                }  
                if (blocks > 1 && x + nodes[i].gain >= nodes[nxt].need) {
                    ok = 1;
                    nodes[i].gain += nodes[nxt].gain;
                    nodes[i].need = min(nodes[i].need, nodes[nxt].need);
                    remove(nxt);
                    blocks--;
                }
                if (!ok) break;
            }
        }
        if(blocks > 1) return false;
        for (int i = 0; i < n; i++) if (in[i]) return x + nodes[i].gain >= nodes[i].need;
    };
    ll l = 0, r = 1e13, mid, ans;
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    solve();  
    return 0; 
}