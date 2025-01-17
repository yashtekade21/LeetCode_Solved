class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int og_arr = 0;
        for (auto& i : derived) {
            og_arr ^= i;
        }

        return og_arr == 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
