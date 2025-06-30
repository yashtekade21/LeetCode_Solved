class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;

        int ans = 0;

        for(int &num : nums) {
            mp[num]++;
        }

        for(int &num : nums) {
            int minNum = num;
            int maxNum = num+1;

            if(mp.count(maxNum)) {
                ans = max(ans, mp[minNum] + mp[maxNum]);
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
