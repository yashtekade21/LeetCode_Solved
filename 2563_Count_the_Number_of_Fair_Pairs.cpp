class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0,n = nums.size();

        for(int i=0;i<n;i++){
            long long low = lower - nums[i];
            long long high = upper - nums[i];

            ans += bin_search(i+1,n-1,high+1,nums) - bin_search(i+1,n-1,low,nums);
        }
        return ans;
    }

private:
    long long bin_search(long long low,long long high,int t,vector<int> &nums){
        while(low<=high){
            long long mid = (low+high)/2;
            if(nums[mid] >= t)
                high = mid-1;
            else
                low = mid+1;
        }
        return high;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
