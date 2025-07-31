class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> ans, prev, curr;

        for (int i = 0; i < n; i++) {
            for (auto& num : prev) {
                int OR = arr[i] | num;
                curr.insert(OR);
                ans.insert(OR);
            }
            curr.insert(arr[i]);
            ans.insert(arr[i]);

            prev = curr;
            curr.clear();
        }
        return ans.size();
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
