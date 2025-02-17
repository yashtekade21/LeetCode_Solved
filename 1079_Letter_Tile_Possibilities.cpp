class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        sort(tiles.begin(),tiles.end());
        vector<bool> vis(n,false);
        
        return dfs(tiles,vis);
    }
private:
    int dfs(string& tiles,vector<bool>& vis){
        int count = 0;
        for(int i=0;i<tiles.size();i++){
            if(vis[i] || (i > 0 && tiles[i] == tiles[i-1] && !vis[i-1]))
                continue;
            
            vis[i] = true;
            count++;
            count += dfs(tiles,vis);
            vis[i] = false;
        }
        return count;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
