class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int subSum = nums[n-1];

        for(int i=n-2;i>=0;i--){
            if(nums[i] == nums[i+1])
                continue;
            if(nums[i] <= 0)
                break;
            subSum += nums[i];
        }
        return subSum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
