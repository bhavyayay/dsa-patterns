class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        unordered_map<int, int> freq;

        int left = 0, right = 0;

        for (auto [time, idx] : q) {

            while (right < logs.size() && logs[right][1] <= time) {
                freq[logs[right][0]]++;
                right++;
            }

            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    freq.erase(server);
                }

                left++;
            }

            ans[idx] = n - freq.size();
        }

        return ans;
    }
};