class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while (word.length() < k) {
            int n = word.length();
            for (int i = 0; i < n; i++) {
                int ch = (word[i] - 'a' + 1) % 26;
                word += (ch + 'a');
                if(word.length() == k)
                    break;
            }
        }
        return word.back();
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
