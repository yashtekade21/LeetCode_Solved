class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = INT_MAX, n = nums.size();
        long long pre_sum = 0;
        deque<pair<long long , int>> q;
        q.push_back({0, -1});

        for (int i = 0; i < n; i++) {
            pre_sum += nums[i]; 

            while (!q.empty() && pre_sum - q.front().first >= k) {
                int cur_sum = q.front().first;
                int end_ind = q.front().second;
                q.pop_front();

                ans = min(ans, i - end_ind);
            }
            while (!q.empty() && q.back().first >= pre_sum)
                q.pop_back();

            q.push_back({pre_sum, i});
        }
        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
