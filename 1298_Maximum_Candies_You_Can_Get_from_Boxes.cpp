class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        return bfs(status, candies, keys, containedBoxes, initialBoxes);
    }

private:
    int bfs(vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            vector<int>& initialBoxes) {
        int n = candies.size();
        int totalCandies = 0;
        vector<bool> visited(n, false);
        unordered_set<int> seenBoxes;

        queue<int> q;

        for (int& box : initialBoxes) {
            seenBoxes.insert(box);
            if (status[box] && !visited[box]) {
                q.push(box);
                visited[box] = true;
                totalCandies += candies[box];
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            for (auto& insideBox : containedBoxes[box]) {
                seenBoxes.insert(insideBox);
                if (status[insideBox] && !visited[insideBox]) {
                    q.push(insideBox);
                    visited[insideBox] = true;
                    totalCandies += candies[insideBox];
                }
            }
            for (auto& boxKey : keys[box]) {
                status[boxKey] = 1;
                if (seenBoxes.find(boxKey) != seenBoxes.end() &&
                    !visited[boxKey]) {
                    q.push(boxKey);
                    visited[boxKey] = true;
                    totalCandies += candies[boxKey];
                }
            }
        }

        return totalCandies;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
