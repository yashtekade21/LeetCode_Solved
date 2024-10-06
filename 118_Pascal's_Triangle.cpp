class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
            ans.emplace_back(generateRow(i));
        return ans;
    }
    private:
    vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.emplace_back(ans);
    for(int i=1;i<row;i++){
        ans *= (row-i);
        ans /= i;

        ansRow.emplace_back(ans);
    }
    return ansRow;
}
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
