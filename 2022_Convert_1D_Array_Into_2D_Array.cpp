class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> cpy(m,vector<int> (n));
        if(m*n != original.size())
            return {};
        else
        {
            int index=0;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cpy[i][j] = original[index];
                    index++;
                }
            }
            // for(int i=0;i<min(m,n);i++)
            //     for(int j=0;j<max(m,n);j++)
            //         cout<<cpy[i][j]<<" ";
                
        }
        return cpy;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
