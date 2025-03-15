class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int maxMoney = INT_MIN, minMoney = INT_MAX;
        for (auto& num : nums) {
            maxMoney = max(maxMoney, num);
            minMoney = min(minMoney, num);
        }

        int l = minMoney, r = maxMoney;
        int minCap = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (checkCapability(nums, mid, k)) {
                minCap = min(minCap, mid);
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return minCap;
    }

private:
    bool checkCapability(vector<int>& nums, int& mid, int k) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= mid) {
                k--;
                i += 2;
            } else
                i++;
        }
        if (k <= 0)
            return true;
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
