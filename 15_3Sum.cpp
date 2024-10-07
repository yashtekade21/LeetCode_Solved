class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i+1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    st.insert(temp);
                    j++;
                    k--;

                    if (j>i && nums[k] == nums[k + 1])
                        k--;
                    if (j < n-1 && nums[j] == nums[j - 1])
                        j++;
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
