#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<int MOD>
struct Mint {
    int v;
    Mint(long long _v = 0) {
        if (_v < 0) v = (_v % MOD + MOD) % MOD;
        else v = _v % MOD;
    }

    Mint& operator+=(const Mint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = 1LL * v * o.v % MOD; return *this; }
    
    friend Mint qpow(Mint a, long long p) {
        Mint res = 1;
        for (; p; p >>= 1, a *= a) if (p & 1) res *= a;
        return res;
    }
    
    Mint inv() const { return qpow(*this, MOD - 2); }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    
    bool operator==(const Mint& o) const { return v == o.v; }
    bool operator!=(const Mint& o) const { return v != o.v; }
    friend ostream& operator<<(ostream& os, const Mint& a) { return os << a.v; }
    friend istream& operator>>(istream& is, Mint& a) { long long t; is >> t; a = Mint(t); return is; }
};

const int MOD = 998244353;
using mint = Mint<MOD>;

struct ACAutomaton {
    struct Node {
        int son[26];
        int fail;
        int count; // 记录以该节点结尾的单词数量
        Node() { fill(son, son + 26, 0); fail = 0; count = 0; }
    };

    vector<Node> trie;

    ACAutomaton() { trie.emplace_back(); }

    void insert(string s) {
        int u = 0;
        for (char c : s) {
            int v = c - 'a';
            if (!trie[u].son[v]) {
                trie[u].son[v] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].son[v];
        }
        trie[u].count++;
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (trie[0].son[i]) q.push(trie[0].son[i]);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                int &v = trie[u].son[i];
                if (v) {
                    trie[v].fail = trie[trie[u].fail].son[i];
                    q.push(v);
                } else {
                    v = trie[trie[u].fail].son[i];
                }
            }
        }
    }

    int query(string t) {
        int u = 0, res = 0;
        for (char c : t) {
            u = trie[u].son[c - 'a'];
            for (int j = u; j && trie[j].count != -1; j = trie[j].fail) {
                res += trie[j].count;
                trie[j].count = -1; 
        	}
		}
        return res;
    }
};

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	for (int i = 1; i <= k; i++) {
		cin >> s;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}