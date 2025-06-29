class Solution {
public:
    int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        vector<int> pow(n);
        pow[0] = 1;
        
        for(int i = 1; i<n; i++)
            pow[i] = (pow[i-1] * 2) % MOD;
        
        
        int l = 0, r = n-1;
        int ans = 0;
        while(l <= r) {
            
            if(nums[l] + nums[r] <= target) {
                int diff = r-l;
                ans = (ans % MOD + pow[diff]) % MOD;
                l++;
            } else {
                r--;
            }
            
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
