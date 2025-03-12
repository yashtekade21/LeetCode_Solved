class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int posCnt = 0,negCnt = 0;

        for(auto& num:nums){
            if(num > 0)
                posCnt++;
            else if(num < 0)
                negCnt++;
        }

        return max(posCnt,negCnt);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
