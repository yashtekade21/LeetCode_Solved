class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();

        set<int, greater<int>> st;

        for (auto& num : nums) {
            st.insert(num);
        }

        // for(auto& it:st)
        //     cout<<it<<" ";


        auto it = st.begin();
        if (st.size() < 3) {
            return *it;
        }

        for (int i = 0; i < 2; i++) {
            it++;
        }

        return *it;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
