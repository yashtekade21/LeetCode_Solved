class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = INT_MIN;

        for (int i = 0; i < n1; i++) {
            int j = upper_bound(nums2.begin() + i, nums2.end(), nums1[i],
                                greater<int>()) -
                    nums2.begin() - 1;

            if (i <= j && nums1[i] <= nums2[j])
                ans = max(ans, j - i);
        }

        return ans == INT_MIN ? 0 : ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
