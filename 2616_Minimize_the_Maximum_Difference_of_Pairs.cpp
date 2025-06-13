class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0)
            return 0;
            
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums[n - 1] - nums[0];
        int ans = INT_MAX;

        while (l <= r) {
            int mid = (l + r) / 2;

            // cntPairs
            int i = 0;
            int pairs = 0;
            while (i + 1 < n) {
                if (nums[i + 1] - nums[i] <= mid) {
                    pairs++;
                    i += 2;
                } else
                    i++;
            }
            // cntPairs

            if (pairs >= p) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
