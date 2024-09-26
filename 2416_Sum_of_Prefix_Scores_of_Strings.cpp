class Solution {
public:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        int count;

        TrieNode() : count(0) {}
    };

    TrieNode* root = new TrieNode();

    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        for (string s : words)
            insert(s);

        for (int i = 0; i < words.size(); i++)
            ans.emplace_back(getSum(words[i]));

        return ans;
    }

private:
    void insert(string s) {
        TrieNode* node = root;
        for (char c : s) {
            if (node->children[c - 'a'] == NULL)
                node->children[c - 'a'] = new TrieNode();

            node = node->children[c - 'a'];
            node->count++;
        }
    }

    int getSum(string s) {
        TrieNode* node = root;
        int sum = 0;
        for (char c : s) {
            node = node->children[c - 'a'];
            sum += node->count;
        }
        return sum;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
