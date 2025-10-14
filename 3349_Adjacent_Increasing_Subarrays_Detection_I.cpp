class Solution {
public:
    int n;
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        n = nums.size();

        for (int i = 0; i <= n - 2*k; i++) {
            if (isIncreasing(i, i + k, nums) &&
                isIncreasing(i + k, i + k + k, nums))
                return true;
        }
        return false;
    }

private:
    bool isIncreasing(int s, int e, vector<int>& nums) {
        for (int i = s+1; i < e; i++) {
            if (nums[i] <= nums[i-1])
                return false;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
