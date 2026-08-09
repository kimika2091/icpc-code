#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }
    multiset<int> dups;
    set<int> uniques;
    for (auto const& [val, count] : counts) {
        uniques.insert(val);
        for (int i = 0; i < count - 1; ++i) {
            dups.insert(val);
        }
    }
    int v = 0;
    while (true) {
        if (uniques.count(v)) {
            uniques.erase(v);
            v++;
        } 
        else {
            auto it_dup = dups.lower_bound(2 * v + 1);
            if (it_dup != dups.end()) {
                dups.erase(it_dup);
                v++;
            } 
            else {
                if (!uniques.empty()) {
                    auto it_unique = uniques.end();
                    --it_unique; 
                    if (*it_unique >= 2 * v + 1) {
                        uniques.erase(it_unique);
                        v++;
                    } else {
                        break;
                    }
                } else {
                    break; 
                }
            }
        }
    }
    cout << v << '\n';
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
	}
    return 0;
}