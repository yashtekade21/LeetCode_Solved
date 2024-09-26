class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int xor_val=0;
            for(int j=queries[i][0];j<=queries[i][queries[i].size()-1];j++)
            {
                xor_val = xor_val ^ arr[j];  
            }
            ans.emplace_back(xor_val);
        }
        return ans;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
