class Solution {
public:
    class TrieNode {
    public:
        vector<TrieNode*> children;
        TrieNode() : children(10, nullptr) {}
    };
    TrieNode* root = new TrieNode();
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        for(int i:arr1)
            insert(to_string(i));

        int lcp=0;

        for(int i:arr2)
            lcp = max(lcp,search(to_string(i)));
        return lcp;
    }

    private:
    void insert(string s)
    {
        TrieNode* node = root;
        for(char c:s)
        {
            if(node->children[c-'0'] == NULL)
                node->children[c-'0'] = new TrieNode();
            
            node = node->children[c-'0'];
        }
    }

    int search(string s)
    {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++)
        {
            if(node->children[s[i]-'0'] == NULL)
                return i;
            
            node = node->children[s[i]-'0'];
        }
        return s.length();
    }
};

static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
