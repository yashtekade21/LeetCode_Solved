class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isLast;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            isLast = false;
        }
    };

    TrieNode* root = new TrieNode();

    int minExtraChar(string s, vector<string>& dictionary) {
        for (string word : dictionary)
            insert(word);

        int dp[s.length() + 1];
        fill(dp, dp + s.length() + 1, 0);

        for (int i = s.length() - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            TrieNode* node = root;
            for (int j = i; j < s.length(); j++) {
                int x = s[j] - 'a';
                if (node->children[x] == nullptr)
                    break;
                node = node->children[x];
                if (node->isLast)
                    dp[i] = min(dp[i], dp[j + 1]);
            }
        }
        return dp[0];
    }

private:
    void insert(string s) {
        TrieNode* node = root;
        for (char c : s) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isLast = true;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
