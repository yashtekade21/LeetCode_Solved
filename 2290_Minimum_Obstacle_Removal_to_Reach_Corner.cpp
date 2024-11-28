class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        return zero1bfs(grid);
    }
private:
    int zero1bfs(vector<vector<int>>& grid){
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> obs_cnt(m,vector<int>(n,INT_MAX));
        vector<vector<int>> dirs= {
            {0,1},{0,-1},{-1,0},{1,0}
        };

        deque<vector<int>> d;
        d.emplace_front(vector<int>{0,0,0});
        obs_cnt[0][0] = 0;

        while(!d.empty()){
            vector<int> v = d.front();
            int row = v[0],col = v[1], obs = v[2];
            d.pop_front();

            if(row == m-1 && col == n-1)
                return obs;

            for(auto dir:dirs){
                int new_row = row+dir[0],new_col = col+dir[1];

                if(new_row >= 0 && new_col >= 0 && new_row < m && new_col < n && obs_cnt[new_row][new_col] == INT_MAX){
                    if(grid[new_row][new_col] == 1){
                        d.emplace_back(vector<int>{new_row,new_col,obs+1});
                        obs_cnt[new_row][new_col] = obs+1;
                    }
                    else{
                        d.emplace_front(vector<int>{new_row,new_col,obs});
                        obs_cnt[new_row][new_col] = obs;
                    }

                }
            }
        }
        return obs_cnt[m-1][n-1];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
