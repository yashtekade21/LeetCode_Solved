class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        while(1){
            vector<int> mp(101,0);
            int notUniq = 0;

            for(auto& num:nums){
                mp[num]++;

                if(mp[num] == 2)
                    notUniq++;
            }

            if(notUniq==0)
                break;
            
            nums.erase(nums.begin(),nums.begin() + min(n,3));
            n = nums.size();
            ans++;
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
