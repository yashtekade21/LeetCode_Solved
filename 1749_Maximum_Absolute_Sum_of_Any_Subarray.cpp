class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxSubSum,minSubSum;
        kadaneAlgo(nums,n,maxSubSum,minSubSum);

        return max(abs(minSubSum),abs(maxSubSum));
    }
private:
    void kadaneAlgo(vector<int>& nums,int n,int& maxSubSum,int& minSubSum){
        int curMaxSum = nums[0], curMinSum = nums[0];
        maxSubSum = curMaxSum;
        minSubSum = curMinSum;

        for(int i=1;i<n;i++){
            curMaxSum = max(nums[i], curMaxSum + nums[i]);
            curMinSum = min(nums[i], curMinSum + nums[i]);

            maxSubSum = max(maxSubSum,curMaxSum);
            minSubSum = min(minSubSum,curMinSum);
        }
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
