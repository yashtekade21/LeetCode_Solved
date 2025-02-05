class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count_displaced = 0;
        int size = s1.length();

        if (s1 == s2)
            return true;
        vector<int> s1map(26, 0), s2map(26, 0);

        for (int i = 0; i < size; i++) {
            if (s1[i] != s2[i])
                count_displaced++;

            if (count_displaced > 2)
                return false;

            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (s1map[i] != s2map[i])
                return false;
        }

        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
