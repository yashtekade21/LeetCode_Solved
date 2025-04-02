class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int fNum = INT_MAX, sNum = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= fNum)
                fNum = nums[i];
            else if (nums[i] <= sNum) {
                sNum = nums[i];
            }
            else
                return true;
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
