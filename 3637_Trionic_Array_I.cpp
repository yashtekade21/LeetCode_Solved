class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;

        if (i == 0 || i == n - 1)
            return false;

        while (i + 1 < n && nums[i] > nums[i + 1])
            i++;

        if (i == n - 1)
            return false;

        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;

        return i == n - 1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
