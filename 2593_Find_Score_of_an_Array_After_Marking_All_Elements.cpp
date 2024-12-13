class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        long long score = 0;
        while (!pq.empty()) {
            int num = pq.top().first, idx = pq.top().second;
            pq.pop();

            if (!vis[idx]) {
                score += num;
                vis[idx] = true;
                if (idx - 1 >= 0 && !vis[idx - 1])
                    vis[idx - 1] = true;
                if (idx + 1 <= n - 1 && !vis[idx + 1])
                    vis[idx + 1] = true;
            } else
                continue;
        }
        return score;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
