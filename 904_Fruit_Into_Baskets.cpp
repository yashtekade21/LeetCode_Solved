class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;

        unordered_set<int> st;
        vector<int> freq(n,0);
        int j = 0, i = 0;
        int cntFruit = 0;

        while (j < n) {
            st.insert(fruits[j]);
            freq[fruits[j]]++;
            cntFruit++;

            while (st.size() > 2) {
                cntFruit--;
                if(--freq[fruits[i]] == 0)
                    st.erase(fruits[i]);

                i++;
            }

            ans = max(ans, cntFruit);
            j++;
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
