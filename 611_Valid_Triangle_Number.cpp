class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        if(n < 3)
            return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n - 3; i++) {
            if(nums[i] == 0)
                continue;

            for (int j = i + 1; j <= n - 2; j++) {
                int sumij = nums[i] + nums[j];

                int maxIdx = binSearch(nums,j+1,n-1,sumij);

                ans += (maxIdx != -1) ? (maxIdx - j) : 0;
            }
        }
        return ans;
    }
private:
    int binSearch(vector<int>& nums,int l,int r,int sidesSum){
        int finalMid= -1;

        while(l <= r){
            int m = (l+r)/2;

            if(nums[m] < sidesSum){
                finalMid = m;
                l = m + 1;
            }else
                r = m-1;
        }
        return finalMid;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
