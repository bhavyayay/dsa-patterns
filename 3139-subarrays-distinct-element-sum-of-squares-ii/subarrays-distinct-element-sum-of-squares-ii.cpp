class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<long long> sum, sq, lazy;

    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;

        long long v = lazy[node];
        long long len = r - l + 1;

        sq[node] += 2 * v * sum[node] + len * v * v;
        sum[node] += len * v;

        if (l != r) {
            lazy[2 * node + 1] += v;
            lazy[2 * node + 2] += v;
        }

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            lazy[node]++;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;

        update(2 * node + 1, l, mid, ql, qr);
        update(2 * node + 2, mid + 1, r, ql, qr);

        sum[node] = sum[2 * node + 1] + sum[2 * node + 2];
        sq[node] = sq[2 * node + 1] + sq[2 * node + 2];
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int l = last[nums[i]] + 1;
            update(0, 0, n - 1, l, i);

            ans = (ans + sq[0]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};