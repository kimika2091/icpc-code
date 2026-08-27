#include <bits/stdc++.h>
using namespace std;

using U64 = unsigned long long;

// 只用于很小的随机数据：Trie 的非根节点数必须不超过 63。
struct BruteForce {
    struct Node {
        array<int, 26> next{};
        int parent = -1;
    };

    int n, m;
    vector<Node> trie{1};
    vector<U64> pathMask;
    vector<unordered_map<U64, int>> memo;

    U64 insert(const string& s) {
        int u = 0;
        U64 mask = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[u].next[c] == 0) {
                int v = static_cast<int>(trie.size());
                if (v > 63) {
                    cerr << "Brute-force case is too large.\n";
                    exit(1);
                }
                trie[u].next[c] = v;
                trie.push_back(Node{});
                trie[v].parent = u;
            }
            u = trie[u].next[c];
            mask |= 1ULL << (u - 1);  // 一个非根节点对应一条缓存边
        }
        return mask;
    }

    bool isValidCache(U64 mask) const {
        // 缓存必须是祖先封闭的：保留一个节点时必须保留其父边。
        for (int u = 1; u < static_cast<int>(trie.size()); ++u) {
            if (((mask >> (u - 1)) & 1ULL) == 0) continue;
            int p = trie[u].parent;
            if (p != 0 && ((mask >> (p - 1)) & 1ULL) == 0) return false;
        }
        return true;
    }

    int dfs(int requestId, U64 cache) {
        if (requestId == n) return 0;
        if (auto it = memo[requestId].find(cache); it != memo[requestId].end()) {
            return it->second;
        }

        U64 requestPath = pathMask[requestId];
        int cost = __builtin_popcountll(requestPath & ~cache);
        U64 loaded = cache | requestPath;

        if (__builtin_popcountll(loaded) <= m) {
            return memo[requestId][cache] = cost + dfs(requestId + 1, loaded);
        }

        int best = INT_MAX;
        // 枚举处理完当前请求后留下的缓存集合。
        // loaded 的祖先封闭子集都能通过不断删除叶子得到。
        for (U64 kept = loaded;; kept = (kept - 1) & loaded) {
            if (__builtin_popcountll(kept) == m && isValidCache(kept)) {
                best = min(best, dfs(requestId + 1, kept));
            }
            if (kept == 0) break;
        }

        return memo[requestId][cache] = cost + best;
    }

    void solve() {
        cin >> n >> m;
        pathMask.resize(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            pathMask[i] = insert(s);
        }
        memo.resize(n);
        cout << dfs(0, 0) << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BruteForce brute;
    brute.solve();
    return 0;
}
