class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(),nums.end());

        unordered_map<int,int> mp;

        int i=0,j=0;
        long long ans = 0;
        while(j < n){
            if(nums[j] == maxNum){
                mp[maxNum]++;
            }
            while(mp[maxNum] == k){
                ans += (n-j);
                if(nums[i] == maxNum)
                    mp[maxNum]--;
                i++;
            }
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
