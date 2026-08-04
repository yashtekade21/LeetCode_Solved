class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int minEl = INT_MAX, maxEl = INT_MIN;
        unordered_map<int, bool> mp;

        for (auto& num : nums) {
            mp[num] = true;
            minEl = min(minEl, num);
            maxEl = max(maxEl, num);
        }

        vector<int> ans;
        for (int num = minEl; num <= maxEl; num++) {
            if (mp.find(num) == mp.end())
                ans.push_back(num);
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
