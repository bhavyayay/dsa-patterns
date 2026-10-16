class Solution {
public:
    long long MOD = 1e9 + 7;
    vector<long long> s, sq, lazy;

    void push(int i, int l, int r) {
        if (lazy[i] == 0) return;

        long long v = lazy[i], len = r - l + 1;

        sq[i] += 2 * v * s[i] + len * v * v;
        s[i] += len * v;

        if (l != r) {
            lazy[2*i+1] += v;
            lazy[2*i+2] += v;
        }

        lazy[i] = 0;
    }

    void update(int i, int l, int r, int ql, int qr) {
        push(i, l, r);

        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            lazy[i]++;
            push(i, l, r);
            return;
        }

        int m = (l + r) / 2;

        update(2*i+1, l, m, ql, qr);
        update(2*i+2, m+1, r, ql, qr);

        s[i] = s[2*i+1] + s[2*i+2];
        sq[i] = sq[2*i+1] + sq[2*i+2];
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        s.assign(4*n, 0);
        sq.assign(4*n, 0);
        lazy.assign(4*n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            update(0, 0, n-1, last[nums[i]]+1, i);
            ans = (ans + sq[0]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};