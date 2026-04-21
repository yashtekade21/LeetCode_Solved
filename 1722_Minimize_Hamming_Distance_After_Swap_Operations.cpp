class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int ans = 0;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& vec : allowedSwaps)
            DSU(vec[0], vec[1]);

        unordered_map<int, unordered_map<int, int>> groupFreq;

        for (int i = 0; i < n; i++) {
            int curr = source[i];

            int parent = find(i);
            groupFreq[parent][curr]++;
        }

        for (int i = 0; i < n; i++) {
            int parent = find(i);

            if (groupFreq[parent][target[i]] > 0)
                groupFreq[parent][target[i]]--;
            else
                ans++;
        }

        return ans;
    }

private:
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void DSU(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
            swap(rootX, rootY);

        parent[rootY] = rootX;

        if (rank[rootX] == rank[rootY])
            rank[rootX]++;
    }
};
