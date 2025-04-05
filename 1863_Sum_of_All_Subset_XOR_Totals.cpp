class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> allSubs;

        vector<int> subSet;
        int n = nums.size(),ans=0;

        findAllSubs(nums,0,subSet,allSubs);

        for(auto& subset:allSubs){
            int xorOp = 0;
            for(auto& num:subset)
                xorOp ^= num;
            
            ans += xorOp;
        }
        return ans;
    }
private:
    void findAllSubs(vector<int>& nums,int i,vector<int>& subSet,vector<vector<int>>& allSubs){
        if(i > nums.size()-1){
            allSubs.push_back(subSet);
            return;
        }

        subSet.push_back(nums[i]);
        findAllSubs(nums,i+1,subSet,allSubs);
        subSet.pop_back();
        findAllSubs(nums,i+1,subSet,allSubs);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
