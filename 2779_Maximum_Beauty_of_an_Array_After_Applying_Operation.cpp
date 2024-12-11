class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> range(n);

        for (int i = 0; i < n; i++) {
            range[i] = {nums[i] - k, nums[i] + k};
        }
        sort(range.begin(), range.end());

        deque<int> dq;
        int max_op = 0;

        for (auto it : range) {
            while (!dq.empty() && dq.front() < it.first)
                dq.pop_front();

            dq.push_back(it.second);
            max_op = max(max_op, (int)dq.size());
        }

        return max_op;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
