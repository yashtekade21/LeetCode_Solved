class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++) 
            ans.push_back(calcRow(i));

        return ans;
    }

private:
    vector<int> calcRow(int rowNum) {
        vector<int> rowVals;
        int num = 1;

        rowVals.push_back(num);
        for (int i = 1; i < rowNum; i++) {
            num *= (rowNum - i);
            num /= i;
            rowVals.push_back(num);
        }
        return rowVals;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
