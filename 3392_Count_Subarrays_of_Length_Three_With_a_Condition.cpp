class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int i = 0, j = 0;
        while (j < n) {
            if (j - i + 1 == 3) {
                float sum = (float)nums[i] + (float)nums[j];
                float half = (float)nums[j - 1] / 2.0;
                ans += (sum == half) ? 1 : 0;
                // cout<<i<<" "<<j<<endl;
                i++;
            }
            j++;
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
