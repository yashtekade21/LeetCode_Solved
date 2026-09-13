class Solution {
public:
    int shiftAndCount(vector<vector<int>>& A, vector<vector<int>>& B,
                      int x_shift, int y_shift) {
        int n = A.size();
        int leftShiftCount = 0;
        int rightShiftCount = 0;

        int A_row = 0;

        for (int B_row = x_shift; B_row < n; B_row++) {
            int A_col = 0;
            for (int B_col = y_shift; B_col < n; B_col++) {
                if (B[B_row][B_col] == 1 && B[B_row][B_col] == A[A_row][A_col])
                    leftShiftCount++;
                if (B[B_row][A_col] == 1 && B[B_row][A_col] == A[A_row][B_col])
                    rightShiftCount++;
                A_col++;
            }
            A_row++;
        }
        return max(leftShiftCount, rightShiftCount);
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOverlap = 0;
        for (int x_shift = 0; x_shift < n; x_shift++) {
            for (int y_shift = 0; y_shift < n; y_shift++) {
                maxOverlap =
                    max(maxOverlap, shiftAndCount(A, B, x_shift, y_shift));
                maxOverlap =
                    max(maxOverlap, shiftAndCount(B, A, x_shift, y_shift));
            }
        }
        return maxOverlap;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
