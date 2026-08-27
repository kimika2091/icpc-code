#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        array<int, 26> next{};
        int parent = 0;
        int cachedChildren = 0;
        bool exist = false;
    };

    vector<Node> tr{1};
    vector<vector<int>> occurrence{1};
    vector<int> ptr;

    // (next occurrence, node). We evict the leaf used farthest in the future.
    priority_queue<pair<int, int>> q;

    long long cachedEdges = 0;
    long long ans = 0;

    void insert(const string& s, int requestId) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (tr[u].next[c] == 0) {
                int v = static_cast<int>(tr.size());
                tr[u].next[c] = v;
                tr.emplace_back();
                tr[v].parent = u;
                occurrence.emplace_back();
            }
            u = tr[u].next[c];
            occurrence[u].push_back(requestId);
        }
    }

    int nextUse(int u, int inf) const {
        if (ptr[u] == static_cast<int>(occurrence[u].size())) return inf;
        return occurrence[u][ptr[u]];
    }

    void pushLeaf(int u, int inf) {
        q.push({nextUse(u, inf), u});
    }

    void process(const string& s, int m, int inf) {
        int u = 0;
        for (char ch : s) {
            int p = u;
            u = tr[u].next[ch - 'a'];

            if (!tr[u].exist) {
                tr[u].exist = true;
                ++tr[p].cachedChildren;
                ++cachedEdges;
                ++ans;
            }

            // This occurrence has now been processed.
            ++ptr[u];
        }

        // Every other cached leaf already has a valid (or lazily stale) heap item.
        if (tr[u].cachedChildren == 0) pushLeaf(u, inf);

        while (cachedEdges > m) {
            auto [when, v] = q.top();
            q.pop();

            // Lazy deletion: the node may no longer be a leaf, or its next-use
            // time may have changed since this heap item was inserted.
            if (!tr[v].exist || tr[v].cachedChildren != 0 ||
                when != nextUse(v, inf)) {
                continue;
            }

            int p = tr[v].parent;
            tr[v].exist = false;
            --cachedEdges;
            --tr[p].cachedChildren;

            // Removing v may make its parent a new deletable leaf.
            if (p != 0 && tr[p].exist && tr[p].cachedChildren == 0) {
                pushLeaf(p, inf);
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> requests(n);
    Trie trie;
    for (int i = 0; i < n; ++i) {
        cin >> requests[i];
        trie.insert(requests[i], i);
    }

    trie.ptr.assign(trie.tr.size(), 0);
    for (const string& s : requests) {
        trie.process(s, m, n);
    }

    cout << trie.ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
