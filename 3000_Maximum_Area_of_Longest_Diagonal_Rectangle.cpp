class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int m = dimensions.size();
        long long area = 0;
        double diagLen = 0;

        for (int i = 0; i < m; i++) {
            int len = dimensions[i][0];
            int wid = dimensions[i][1];

            double tempDiagLen = (double)hypot(len, wid);
            int tempArea = len * wid;
            // cout<<len<<"  "<<wid<<"  "<<tempDiagLen<<"  "<<tempArea<<endl;

            if (tempDiagLen > diagLen) {
                diagLen = tempDiagLen;
                area = tempArea;
            } else if (tempDiagLen == diagLen && tempArea > area) {
                diagLen = tempDiagLen;
                area = tempArea;
            }
        }
        return area;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
