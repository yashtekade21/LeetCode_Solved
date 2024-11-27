#include <deque>
#include <iostream>
#include <unordered_set>
#include <utility> // For std::pair
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
            adj[i].emplace_back(i + 1);

        vector<int> ans;
        for (auto r : queries) {
            adj[r[0]].emplace_back(r[1]);
            ans.emplace_back(find_path(adj, n));
        }
        return ans;
    }

private:
    int find_path(vector<vector<int>>& adj, int n) {
        deque<pair<int, int>> d;
        d.push_back({0, 0});

        unordered_set<int> visited;
        visited.insert(0);

        while (!d.empty()) {
            int cur = d.front().first;
            int size = d.front().second;
            d.pop_front();

            if (cur == n - 1)
                return size;

            for (auto n : adj[cur]) {
                if (visited.find(n) == visited.end()) {
                    d.push_back({n, size + 1});
                    visited.insert(n);
                }
            }
        }
        return -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
