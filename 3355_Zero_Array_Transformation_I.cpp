class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArr(n,0);

        for(auto& query:queries){
            int s = query[0], e = query[1];
            diffArr[s]++;
            if(e + 1 < n)
                diffArr[e+1]--;
        }

        int cumSum = 0;
        for(int i=0;i<n;i++){
            cumSum += diffArr[i];
            diffArr[i] = cumSum;
            if(nums[i] > diffArr[i])
                return false;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
