class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),m=queries.size();
        vector<int> check_violation(n);
        
        int i=0,j=0;
        while(i<n){
            if(j < i)
                j = i;
               
            while(j+1 < n && nums[j]%2 != nums[j+1]%2)
                j++;
               
            check_violation[i] = j;
            i++;
        }
        
        vector<bool> ans(m,false);
        
        for(int i=0;i<m;i++){
            int s = queries[i][0];
            int e = queries[i][1];
            
            if(e <= check_violation[s])
                ans[i] = true;
        }
        
        return ans;
    }   
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
