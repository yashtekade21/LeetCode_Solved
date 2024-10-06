class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1,n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;

                    if(j == 0)
                        col0 = 0;
                    else
                        matrix[0][j] = 0;
                }
            }
        }

        for(int i=n-1;i>0;i--){
            for(int j=m-1;j>0;j--){
                if(matrix[i][j] != 0){
                    if(matrix[0][j] == 0 || matrix[i][0] == 0)
                        matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0)
            for(int j=0;j<m;j++)
                matrix[0][j] = 0;

        if(col0==0)
            for(int i=0;i<n;i++)
                matrix[i][0] = 0;

        return;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
