class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int flipsNeeded = 0, totalFlips = 0;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            if (i >= 3 && dq.front() == 1) {
                flipsNeeded--;
                dq.pop_front();
            } else if (i >= 3)
                dq.pop_front();

            if (flipsNeeded % 2 == nums[i]) {
                if (i > n - 3)
                    return -1;

                flipsNeeded++;
                totalFlips++;
                dq.push_back(1);
            } else {
                dq.push_back(0);
            }
        }
        return totalFlips;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
