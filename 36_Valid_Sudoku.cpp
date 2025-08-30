class Solution {
public:
    int m,n;
    bool isValidSudoku(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        vector<bool> isDuplicateinSubBox(9,false);

        for(int idx = 0;idx < 9; idx++){
            if(hasDupInBox(board,idx)){
                isDuplicateinSubBox[idx] = true;
                return false;
            }
        }

        //Check duplicate in rows
        for(int i=0;i<m;i++){
            if(checkDupInRow(board,i)){
                return false;
            }
        }

        for(int j=0;j<n;j++){
            if(checkDupInCol(board,j)){
                return false;
            }
        }

        return true;
    }
private:
    bool hasDupInBox(vector<vector<char>>& board,int boxIdx){
        unordered_set<char> seenVals;

        int rowStart = (boxIdx/3) * 3;
        int colStart = (boxIdx%3) * 3;

        for(int r=rowStart;r< rowStart + 3;r++){
            for(int c = colStart;c < colStart + 3;c++){
                char val = board[r][c];
                if(val != '.'){
                    if(seenVals.find(val) != seenVals.end()){
                        return true;
                    }
                    seenVals.insert(val);
                }
            }
        }
        return false;
    }

    bool checkDupInCol(vector<vector<char>>& board,int colIdx){
        unordered_set<char> st;
        for(int i=0;i<m;i++){
            char val = board[i][colIdx];
            if(val != '.'){
                if(st.find(val) != st.end()){
                    return true;
                }
                st.insert(val);
            }
        }
        return false;

    }

        bool checkDupInRow(vector<vector<char>>& board,int rowIdx){
        unordered_set<char> st;
        for(int j=0;j<n;j++){
            char val = board[rowIdx][j];
            if(val != '.'){
                if(st.find(val) != st.end()){
                    return true;
                }
                st.insert(val);
            }
        }
        return false;

    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
