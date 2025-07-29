class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        vector<int> setBitPos(32, -1);

        for (int i = n - 1; i >= 0; i--) {
            int maxORIdx = i;
            for (int j = 0; j < 32; j++) {
                if (!(nums[i] & (1 << j))) {
                    if (setBitPos[j] != -1)
                        maxORIdx = max(maxORIdx, setBitPos[j]);
                } else
                    setBitPos[j] = i;
            }
            ans[i] = maxORIdx - i + 1;
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
