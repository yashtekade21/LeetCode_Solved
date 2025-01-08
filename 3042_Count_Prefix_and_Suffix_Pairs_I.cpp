struct TrieNode {
    TrieNode* children[26];
    bool isEOS;
};

TrieNode* gen_Node() {
    TrieNode* node = new TrieNode();
    for (int i = 0; i < 26; i++)
        node->children[i] = nullptr;
    return node;
}
class Trie {
public:
    TrieNode* root;
    Trie() { root = gen_Node(); }

    void insert(string s) {
        TrieNode* node = root;
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = gen_Node();
            node = node->children[idx];
        }
        node->isEOS = true;
    }

    bool search(string s) {
        TrieNode* node = root;
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return true;
    }
};
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;

        for (int j = 0; j < n; j++) {
            Trie prefix;
            Trie suffix;

            prefix.insert(words[j]);
            string rev_str = words[j];
            reverse(rev_str.begin(), rev_str.end());
            suffix.insert(rev_str);

            for (int i = 0; i < j; i++) {
                if (words[i].length() > words[j].length())
                    continue;
                
                string rev = words[i];
                reverse(rev.begin(),rev.end());

                ans += (prefix.search(words[i]) && suffix.search(rev));
            }
        }

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
