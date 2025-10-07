class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> mp;
        set<int> st;

        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake == 0) {
                st.insert(i);
            } else if (lake != 0 && mp.find(lake) == mp.end()) {
                ans[i] = -1; 
                mp[lake] = i;
            } else {
                ans[i] = -1;
                auto it = st.lower_bound(mp[lake]);

                if (it == st.end()) 
                    return {};

                int dry = *it;
                st.erase(dry);
                ans[dry] = lake;
                mp[lake] = i;
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
