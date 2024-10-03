class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        vector<int> temp;
        for(int i=n-k;i<n;i++)
            temp.emplace_back(nums[i]);

        for(int i=n-k-1;i>=0;i--)
            nums[i+k] = nums[i];
    
        for(int i=0;i<k;i++)
            nums[i] = temp[i];
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
