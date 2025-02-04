class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0, cur_sum = nums[0];
        for(int i=0;i<n-1;i++){
            if(nums[i] < nums[i+1])
                cur_sum += nums[i+1];
            else{
                max_sum = max(max_sum, cur_sum);
                cur_sum = nums[i+1];
            }
        }

        max_sum = max(max_sum,cur_sum);
        return max_sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
