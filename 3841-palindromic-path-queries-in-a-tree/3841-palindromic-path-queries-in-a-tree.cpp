class Solution {
    struct FenwickTree {
        int size;
        vector<int> tree;
        FenwickTree(int n) : size(n), tree(n + 1, 0) {}
        void add(int i, int delta) {
            for (++i; i <= size; i += i & -i) tree[i] ^= delta;
        }
        int query(int i) {
            int sum = 0;
            for (++i; i > 0; i -= i & -i) sum ^= tree[i];
            return sum;
        }
        int query(int l, int r) {
            return query(r) ^ query(l - 1);
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        vector<int> depth(n, 0);
        vector<vector<int>> up(n, vector<int>(LOG, 0));
        vector<int> tin(n, 0), tout(n, 0);
        int timer = 0;

        auto dfs = [&](auto& self, int u, int p, int d) -> void {
            tin[u] = timer++;
            depth[u] = d;
            up[u][0] = p;
            for (int i = 1; i < LOG; ++i) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
            for (int v : adj[u]) {
                if (v != p) {
                    self(self, v, u, d + 1);
                }
            }
            tout[u] = timer - 1;
        };

        dfs(dfs, 0, 0, 0);

        auto is_ancestor = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[u] >= tout[v];
        };

        auto get_lca = [&](int u, int v) {
            if (is_ancestor(u, v)) return u;
            if (is_ancestor(v, u)) return v;
            for (int i = LOG - 1; i >= 0; --i) {
                if (!is_ancestor(up[u][i], v)) {
                    u = up[u][i];
                }
            }
            return up[u][0];
        };

        FenwickTree ft(n);
        vector<int> char_mask(n);
        for (int i = 0; i < n; ++i) {
            char_mask[i] = (1 << (s[i] - 'a'));
            ft.add(tin[i], char_mask[i]);
        }

        auto get_path_xor = [&](int u, int v) {
            int lca = get_lca(u, v);
            int res = 0;
            int curr = u;
            while (true) {
                int lca_curr = get_lca(curr, lca);
                res ^= ft.query(tin[lca_curr], tin[curr]);
                if (curr == lca) break;
                curr = up[lca][0]; // step past lca if needed or handle carefully
                // Simpler approach with HLD or direct ancestor jumps using Fenwick:
                break;
            }
            return res;
        };

        // Standard path query using node-to-root XOR sums
        vector<int> root_xor(n, 0);
        auto dfs_xor = [&](auto& self, int u, int p, int current_xor) -> void {
            current_xor ^= char_mask[u];
            root_xor[u] = current_xor;
            for (int v : adj[u]) {
                if (v != p) self(self, v, u, current_xor);
            }
        };
        // To handle dynamic updates efficiently, standard tree flattening or HLD is used.
        // Given constraints and standard templates, let's use Euler tour range updates:
        
        vector<int> flat(n);
        vector<int> head(n), heavy(n, -1), parent(n, 0), pos(n, 0);
        int cur_pos = 0;

        auto dfs_sz = [&](auto& self, int u, int p) -> int {
            int size = 1, max_c_sz = 0;
            parent[u] = p;
            for (int& v : adj[u]) {
                if (v != p) {
                    int c_sz = self(self, v, u);
                    size += c_sz;
                    if (c_sz > max_c_sz) {
                        max_c_sz = c_sz;
                        swap(adj[u][0], v);
                    }
                }
            }
            return size;
        };
        dfs_sz(dfs_sz, 0, 0);

        auto dfs_hld = [&](auto& self, int u, int p, int h) -> void {
            head[u] = h;
            pos[u] = cur_pos++;
            bool heavy_child = true;
            for (int v : adj[u]) {
                if (v != p) {
                    self(self, v, u, heavy_child ? h : v);
                    heavy_child = false;
                }
            }
        };
        dfs_hld(dfs_hld, 0, 0, 0);

        FenwickTree hld_ft(n);
        for (int i = 0; i < n; ++i) {
            hld_ft.add(pos[i], char_mask[i]);
        }

        auto query_path = [&](int u, int v) {
            int res = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] > depth[head[v]]) swap(u, v);
                res ^= hld_ft.query(pos[head[v]], pos[v]);
                v = parent[head[v]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            res ^= hld_ft.query(pos[u], pos[v]);
            return res;
        };

        vector<bool> ans;
        for (const auto& q_str : queries) {
            stringstream ss(q_str);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int new_mask = (1 << (c - 'a'));
                int diff = char_mask[u] ^ new_mask;
                if (diff) {
                    char_mask[u] = new_mask;
                    hld_ft.add(pos[u], diff);
                }
            } else {
                int u, v;
                ss >> u >> v;
                int mask = query_path(u, v);
                ans.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return ans;
    }
};