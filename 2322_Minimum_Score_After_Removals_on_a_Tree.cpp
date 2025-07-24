class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> subTreeXOR(n, 0), inTime(n, 0), outTime(n, 0);

        int currTime = 0;

        dfs(0, -1, subTreeXOR, inTime, outTime, currTime, nums, adj);
        // node,  ....

                int ans = INT_MAX;
        for (int node1 = 1; node1 < n; node1++) {
            for (int node2 = node1 + 1; node2 < n; node2++) {
                int xor1, xor2, xor3;
                if (isAncestor(node1, node2, inTime, outTime)) {
                    xor1 = subTreeXOR[node2];
                    xor2 = subTreeXOR[node1] ^ subTreeXOR[node2];
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;
                } else if (isAncestor(node2, node1, inTime, outTime)) {
                    xor1 = subTreeXOR[node1];
                    xor2 = subTreeXOR[node2] ^ subTreeXOR[node1];
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;
                } else {
                    xor1 = subTreeXOR[node1];
                    xor2 = subTreeXOR[node2];
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;
                }

                ans = min(ans, getMinDiff(xor1, xor2, xor3));
            }
        }
        return ans;
    }

private:
    int getMinDiff(int a, int b,int c) {
        int maxXor = max({a, b, c});
        int minXor = min({a, b, c});

        return maxXor - minXor;
    }
    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }
    void dfs(int currNode, int parent, vector<int>& subTreeXOR,
             vector<int>& inTime, vector<int>& outTime, int& currTime,
             vector<int>& nums, unordered_map<int, vector<int>>& adj) {
        subTreeXOR[currNode] = nums[currNode];
        inTime[currNode] = currTime++;

        for (auto& ngbr : adj[currNode]) {
            if (ngbr != parent) {
                dfs(ngbr, currNode, subTreeXOR, inTime, outTime, currTime, nums,
                    adj);
                subTreeXOR[currNode] ^= subTreeXOR[ngbr];
            }
        }

        outTime[currNode] = currTime++;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
