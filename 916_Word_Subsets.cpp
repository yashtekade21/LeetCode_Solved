class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        vector<int> freq_2(26, 0);

        for (auto& word : words2) {
            vector<int> temp(26, 0);

            for (auto& it : word) {
                temp[it - 'a']++;

                freq_2[it - 'a'] = max(freq_2[it - 'a'], temp[it - 'a']);
            }
        }

        for (auto& word : words1) {
            vector<int> temp(26, 0);
            for (auto& ch : word) {
                temp[ch - 'a']++;
            }
            if (is_Universal(freq_2, temp)) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }

private:
    bool is_Universal(vector<int>& freq_2, vector<int>& temp) {
        for (int i = 0; i < 26; i++) {
            if (freq_2[i] > temp[i])
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
