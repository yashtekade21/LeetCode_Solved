class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();
        int alicePoints = INT_MIN;
        unordered_map<int, vector<int>> graph;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        unordered_map<int, int> bobNodes;
        vector<bool> vis(n, false);
        dfsBob(graph, bobNodes, vis, bob, 0);

        vis.assign(n, false);
        int curPoints = 0;
        // dfsAlice(graph, bobNodes, vis, amount, alicePoints, 0, 0, curPoints);
        bfsAlice(graph, bobNodes, amount, alicePoints, 0, 0, curPoints);

        return alicePoints;
    }

private:
    // void dfsAlice(unordered_map<int, vector<int>>& graph,
    //               unordered_map<int, int>& bobNodes, vector<bool>& vis,
    //               vector<int>& amount, int& alicePoints, int curNode,
    //               int timeStamp, int curPoints) {
    //     vis[curNode] = true;

    //     if (bobNodes.find(curNode) == bobNodes.end() ||
    //         bobNodes[curNode] > timeStamp)
    //         curPoints += amount[curNode];
    //     else if (timeStamp == bobNodes[curNode])
    //         curPoints += (amount[curNode] / 2);

    //     if (graph[curNode].size() == 1 &&
    //         curNode != 0) { // trick to identify leaf node in a tree
    //         alicePoints = max(curPoints, alicePoints);
    //     }

    //     for (auto& adj : graph[curNode]) {
    //         if (!vis[adj]) {
    //             dfsAlice(graph, bobNodes, vis, amount, alicePoints, adj,
    //                      timeStamp + 1, curPoints);
    //         }
    //     }
    // }

    void bfsAlice(unordered_map<int, vector<int>>& graph,
                  unordered_map<int, int>& bobNodes, vector<int>& amount,
                  int& alicePoints, int curNode, int timeStamp, int curPoints) {
        queue<vector<int>> q;
        vector<bool> vis((int)amount.size(), false);

        q.push({curNode, timeStamp,
                curPoints}); // curNode = 0, timeStamp = 0, curPoints = 0;

            while (!q.empty()) {
            int curNode = q.front()[0];
            int timeStamp = q.front()[1];
            int curPoints = q.front()[2];
            vis[curNode] = true;

            q.pop();

            if (bobNodes.find(curNode) == bobNodes.end() ||
                bobNodes[curNode] > timeStamp)
                curPoints += amount[curNode];

            else if (bobNodes[curNode] == timeStamp)
                curPoints += (amount[curNode] / 2);

            if (graph[curNode].size() == 1 && curNode != 0)
                alicePoints = max(alicePoints, curPoints);

            for (auto& adj : graph[curNode]) {
                if (!vis[adj])
                    q.push({adj, timeStamp + 1, curPoints});
            }
        }
    }

    bool dfsBob(unordered_map<int, vector<int>>& graph,
                unordered_map<int, int>& bobNodes, vector<bool>& vis,
                int curNode, int timeStamp) {
        vis[curNode] = true;
        bobNodes[curNode] = timeStamp;

        if (curNode == 0)
            return true;

        for (auto& adj : graph[curNode]) {
            if (!vis[adj] && dfsBob(graph, bobNodes, vis, adj, timeStamp + 1)) {
                return true;
            }
        }
        bobNodes.erase(curNode);

        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
