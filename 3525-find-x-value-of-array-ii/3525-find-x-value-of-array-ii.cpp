class Solution {
    struct Node {
        int total_prod;
        vector<int> count;

        Node(int k = 1) : total_prod(1), count(k, 0) {}
    };

    int n, K;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res(K);
        res.total_prod = (1LL * left.total_prod * right.total_prod) % K;

        for (int r = 0; r < K; ++r) {
            res.count[r] = left.count[r];
        }

        for (int r = 0; r < K; ++r) {
            if (right.count[r] > 0) {
                int rem = (1LL * left.total_prod * r) % K;
                res.count[rem] += right.count[r];
            }
        }
        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int rem = nums[start] % K;
            tree[node].total_prod = rem;
            tree[node].count[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % K;
            fill(tree[node].count.begin(), tree[node].count.end(), 0);
            tree[node].total_prod = rem;
            tree[node].count[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void query(int node, int start, int end, int ql, int qr, int target_x, int& cur_prod, int& ans) {
        if (ql <= start && end <= qr) {
            for (int r = 0; r < K; ++r) {
                if (tree[node].count[r] > 0) {
                    if ((1LL * cur_prod * r) % K == target_x) {
                        ans += tree[node].count[r];
                    }
                }
            }
            cur_prod = (1LL * cur_prod * tree[node].total_prod) % K;
            return;
        }

        int mid = start + (end - start) / 2;
        if (ql <= mid) {
            query(2 * node, start, mid, ql, qr, target_x, cur_prod, ans);
        }
        if (qr > mid) {
            query(2 * node + 1, mid + 1, end, ql, qr, target_x, cur_prod, ans);
        }
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        K = k;
        tree.assign(4 * n, Node(K));

        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start_idx = q[2];
            int x = q[3];

            update(1, 0, n - 1, idx, val);

            int ans = 0;
            int cur_prod = 1;
            query(1, 0, n - 1, start_idx, n - 1, x, cur_prod, ans);

            result.push_back(ans);
        }

        return result;
    }
};