class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actualIdx(n);
        iota(actualIdx.begin(), actualIdx.end(), 0);

        sort(actualIdx.begin(), actualIdx.end(),
             [&](int& i, int& j) { return positions[i] < positions[j]; });

        vector<int> ans;
        stack<int> st;
        for (int curIdx : actualIdx) {
            if (directions[curIdx] == 'R') {
                st.push(curIdx);
            } else {
                while (!st.empty() && healths[curIdx] > 0) {
                    int topIdx = st.top();
                    st.pop();

                    if (healths[topIdx] > healths[curIdx]) {
                        healths[topIdx] -= 1;
                        healths[curIdx] = 0;
                        st.push(topIdx);
                    } else if (healths[topIdx] < healths[curIdx]) {
                        healths[curIdx] -= 1;
                        healths[topIdx] = 0;
                    } else {
                        healths[curIdx] = 0;
                        healths[topIdx] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0)
                ans.push_back(healths[i]);
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
