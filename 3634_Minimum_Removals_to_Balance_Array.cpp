class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxBalArr = 0;
        int i = 0, j = 0;
        int minEl = nums[i], maxEl = nums[j];

        while (j < n) {
            maxEl = nums[j];
    
            while (i < j && maxEl > (long long)minEl * k) {
                i++;
                minEl = nums[i];
            }
            maxBalArr = max(maxBalArr, j - i + 1);

            j++;
        }
        return n - maxBalArr;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
