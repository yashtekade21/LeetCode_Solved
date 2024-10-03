class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0,cntOnes=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0){
                cntOnes=0;
                continue;
            }
            cntOnes++;
            if(cntOnes>maxOnes)
                maxOnes = cntOnes;
        }
        return maxOnes;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
