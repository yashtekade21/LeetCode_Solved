class Solution {
public:
#define P pair<int, int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        while (k-- && !pq.empty()) {
            P num = pq.top();
            pq.pop();

            int idx = num.second, ele = num.first;
            nums[idx] = nums[idx] * multiplier;
            pq.push({nums[idx], idx});
        }

        return nums;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
