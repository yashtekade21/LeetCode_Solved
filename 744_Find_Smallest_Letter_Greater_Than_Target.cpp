class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char ans = '#';
        for (int i = 0; i < n; i++) {
            if (letters[i] <= target)
                continue;

            ans = letters[i];
            break;
        }

        return ans != '#' ? ans : letters[0];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
