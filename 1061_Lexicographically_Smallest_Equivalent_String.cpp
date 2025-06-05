class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;

        int n = s1.length();
        for (int i = 0; i < n; i++) {
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string ans = "";

        for (int i = 0; i < baseStr.length(); i++) {
            vector<bool> visited(26, false);
            char minChar = dfs(adj, baseStr, baseStr[i], visited);

            ans += minChar;
        }
        return ans;
    }

private:
    char dfs(unordered_map<char, vector<char>>& adj, string& baseStr, char& ch,
             vector<bool>& visited) {
        visited[ch - 'a'] = true;

        char minChar = ch;
        for (auto& c : adj[ch]) {
            if (!visited[c - 'a']) {
                char eqCh = dfs(adj, baseStr, c, visited);
                minChar = min(minChar, eqCh);
            }
        }
        return minChar;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
