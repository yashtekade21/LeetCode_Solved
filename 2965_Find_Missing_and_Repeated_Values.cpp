class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int,int> mp;
        for(auto& row:grid){
            for(auto& num:row){
                mp[num]++;
            }
        }

        vector<int> result;
        int a, b ;
        for(int i=1;i<=n*n;i++){
            if(mp[i] > 1){
                a = i;
            }
            if(mp[i] == 0){
                b = i;
            }
        }   

        result.push_back(a);
        result.push_back(b);

        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
