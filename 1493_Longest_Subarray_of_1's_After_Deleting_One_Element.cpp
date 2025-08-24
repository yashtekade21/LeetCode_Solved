class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();

        int i=0,j=0;
        int cntZero = 0;
        int ans = 0;

        while(j<n){
            while(cntZero > 1){
                cntZero = (nums[i]==0) ? cntZero-1 : cntZero;
                i++;
            }
            cntZero = (nums[j] == 0) ? cntZero + 1 : cntZero;
            
            if(cntZero <= 1)
                ans = max(ans,j-i);
            j++;
        }
        return ans;
    }
};
