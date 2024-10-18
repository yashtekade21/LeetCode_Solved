class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int i : nums)
            maxOR |= i;
        return count(nums, 0, maxOR, 0);
    }

private:
    int count(vector<int>& nums, int OR, int maxOR, int i) {
        if (i == nums.size()){
            if (OR == maxOR)
                return 1;
        return 0;
    }
    // int include = 0, exclude = 0;

    int include = count(nums, OR | nums[i], maxOR, i + 1);
    int exclude = count(nums, OR, maxOR, i + 1);
    return include + exclude;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
