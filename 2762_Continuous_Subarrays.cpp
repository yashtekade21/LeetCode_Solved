class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i=0,j=0;
        long long ans=0;
        map<int,int> mp;
        
        while(j<nums.size()){
            mp[nums[j]]++;

            while(mp.rbegin()->first - mp.begin()->first > 2){
                mp[nums[i]]--;
                if(!mp[nums[i]])
                    mp.erase(nums[i]);
                i++;
            }
            ans += j-i+1;
            j++;
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
