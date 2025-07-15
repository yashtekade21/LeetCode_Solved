class Solution {
public:
    bool isValid(string word) {
        bool containsConsonant = false;
        bool containsVowel = false;

        for (auto& ch : word) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
                containsVowel = true;
            else if (isalpha(ch))
                containsConsonant = true;
        }

        if (word.length() >= 3 && containsOnlyDigitsAndCharacters(word) &&
            containsConsonant && containsVowel)
            return true;

        return false;
    }

private:
    bool containsOnlyDigitsAndCharacters(string& str) {
        return all_of(str.begin(), str.end(),
                      [](char c) { return isdigit(c) || isalpha(c); });
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
