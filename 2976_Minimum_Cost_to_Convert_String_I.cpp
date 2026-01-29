class Solution {
public:
    vector<vector<long long>> minCost;
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;
        long long ans = 0;
        minCost.assign(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < original.size(); i++) {
            int u = original[i];
            int v = changed[i];
            int c = cost[i];

            adj[u].push_back({v, c});
        }

        for (auto& ch : source)
            dijkstra(ch, adj);

        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i])
                continue;

            if (minCost[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX)
                return -1;

            ans += minCost[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }

private:
    void dijkstra(char& source,
                  unordered_map<char, vector<pair<char, int>>>& adj) {
        priority_queue<pair<int, char>, vector<pair<int, char>>,
                       greater<pair<int, char>>>
            pq;

        pq.push({0, source});

        while (!pq.empty()) {
            int d = pq.top().first;
            char adjNode = pq.top().second;
            pq.pop();

            for (auto& it : adj[adjNode]) {
                char adjNode = it.first;
                int cost = it.second;

                if (minCost[source - 'a'][adjNode - 'a'] > d + cost) {
                    minCost[source - 'a'][adjNode - 'a'] = d + cost;
                    pq.push({d + cost, adjNode});
                }
            }
        }
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
