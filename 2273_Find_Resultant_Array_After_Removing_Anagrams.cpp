class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans = {words[0]};

        for (int i = 1; i < n; i++) {
            if (!isAnagram(words[i], ans.back())) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }

private:
    bool isAnagram(string s1, string s2) {
        vector<int> mp1(26, 0), mp2(26, 0);

        for (auto& ch : s1)
            mp1[ch - 'a']++;

        for (auto& ch : s2)
            mp2[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (mp1[i] != mp2[i])
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
