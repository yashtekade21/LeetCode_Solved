class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> vec(colors.begin(), colors.end());
        for (int i = 0; i < k - 1; i++)
            vec.emplace_back(colors[i]);

        int n = vec.size();
        int i = 0, j = 1;
        int countGroups = 0;

        while (j < n) {
            if (vec[j] == vec[j - 1])
                i = j;

            if (j - i + 1 == k) {
                countGroups++;
                i++;
            }
            j++;
        }
        return countGroups;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
