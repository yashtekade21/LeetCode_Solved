class Spreadsheet {
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid.resize(rows);
        for (int i = 0; i < rows; i++) {
            grid[i].resize(26, 0);
        }
    }

    void setCell(string cell, int value) {
        int alpha = cell[0] - 'A';
        int idx = stoi(cell.substr(1)) - 1;

        grid[idx][alpha] = value;
    }

    void resetCell(string cell) {
        int alpha = cell[0] - 'A';
        int idx = stoi(cell.substr(1)) - 1;

        grid[idx][alpha] = 0;
    }

    int getValue(string formula) {
        size_t posPlus = formula.find('+');

        string X = formula.substr(1, posPlus);
        string Y = formula.substr(posPlus + 1);

        int val1, val2;
        if (isdigit(X[0])) {
            val1 = stoi(X);
        } else {
            int alpha = X[0] - 'A';
            int idx = stoi(X.substr(1)) - 1;

            val1 = grid[idx][alpha];
        }

        if (isdigit(Y[0])) {
            val2 = stoi(Y);
        } else {
            int alpha = Y[0] - 'A';
            int idx = stoi(Y.substr(1)) - 1;

            val2 = grid[idx][alpha];
        }

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
 static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
