class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> incoming(n,0);

        for(auto x:edges)
            incoming[x[1]]++;

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!incoming[i])
                ans.emplace_back(i);
        }
        if(ans.size() > 1)
            return -1;

        return ans[0];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
