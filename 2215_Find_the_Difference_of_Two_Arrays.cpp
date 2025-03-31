class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1,st2;

        for(auto& num:nums1)
            st1.insert(num);

        for(auto& num:nums2)
            st2.insert(num);

        vector<vector<int>> ans(2);

        for(auto& num:st1){
            if(st2.find(num) == st2.end())
                ans[0].emplace_back(num);
        }

        for(auto& num:st2){
            if(st1.find(num) == st1.end())
                ans[1].emplace_back(num);
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
