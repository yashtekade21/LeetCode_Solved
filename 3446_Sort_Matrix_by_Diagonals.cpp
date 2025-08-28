class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int, vector<int>> mp;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(grid[i][j]);
            }
        }

        for (auto& it : mp) {
            if (it.first < 0) {
                sort(it.second.begin(), it.second.end(), greater<int>());
            } else {
                sort(it.second.begin(), it.second.end());
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = mp[i - j].back();
                if (!mp[i - j].empty()) {
                    mp[i - j].pop_back();
                }
                ans[i][j] = num;
            }
        }

        return ans;
    }
};
