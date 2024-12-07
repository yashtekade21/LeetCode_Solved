class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + ((high - low) / 2);
            if (check_divide(mid, nums, maxOperations))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

private:
    bool check_divide(int max_balls, vector<int>& nums, int maxOperations) {
        int ops = 0;
        for (auto i : nums) {
            ops += (i + max_balls - 1) / max_balls - 1;
            if (ops > maxOperations)
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
