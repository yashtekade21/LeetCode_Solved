class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'.'));

        for(int i = 0;i < m;i++){
            int curr = n-1;
            for(int j = n-1;j>=0;j--){
                if(box[i][j] == '#'){
                    ans[curr][m-i-1] = '#';
                    curr--;
                }
                else if(box[i][j] == '*'){
                    ans[j][m-i-1] = '*';
                    curr = j - 1;
                }
            }
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
