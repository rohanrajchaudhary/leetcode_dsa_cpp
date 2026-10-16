class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sqSum = 0;
        long long lazy = 0;
    };

    int n;
    vector<Node> tree;

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0) return;
        long long lazyVal = tree[node].lazy;
        int mid = l + (r - l) / 2;
        apply(2 * node, l, mid, lazyVal);
        apply(2 * node + 1, mid + 1, r, lazyVal);
        tree[node].lazy = 0;
    }

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        tree[node].sqSum = (tree[node].sqSum + 2 * val * tree[node].sum + len * val % MOD * val) % MOD;
        tree[node].sum = (tree[node].sum + len * val) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
        tree[node].sqSum = (tree[2 * node].sqSum + tree[2 * node + 1].sqSum) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());
        unordered_map<int, int> lastSeen;
        long long totalAns = 0;

        for (int r = 0; r < n; ++r) {
            int l = lastSeen.count(nums[r]) ? lastSeen[nums[r]] + 1 : 0;
            update(1, 0, n - 1, l, r, 1);
            lastSeen[nums[r]] = r;
            totalAns = (totalAns + tree[1].sqSum) % MOD;
        }

        return totalAns;
    }
};