class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        map<int, int> mp;

        for (auto& arr : nums1) {
            int id = arr[0];
            int val = arr[1];
            mp[id] += val;
        }

        for (auto& arr : nums2) {
            int id = arr[0];
            int val = arr[1];
            mp[id] += val;
        }

        vector<vector<int>> result;

        for (auto& [id, val] : mp) {
            result.emplace_back(vector<int>{id, val});
        }

        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
