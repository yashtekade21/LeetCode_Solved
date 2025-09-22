class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        vector<int> mp(101, 0);

        for (auto& num : nums) {
            mp[num]++;
            maxFreq = max(maxFreq, mp[num]);
        }

        int ans = 0;
        for (int num=1;num<101;num++) {
            if(mp[num] == maxFreq)
                ans += mp[num];
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
