class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posInd=0,negInd=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posInd] = nums[i];
                posInd+=2;
            }
            else{
                ans[negInd] = nums[i];
                negInd+=2;
            }
        }
        return ans;
    }
};
#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
