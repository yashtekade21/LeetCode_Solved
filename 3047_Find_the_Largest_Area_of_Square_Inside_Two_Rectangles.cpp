class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();

        int maxSide = 0;

        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int topRx = min(topRight[i][0],topRight[j][0]);
                int botLx = max(bottomLeft[i][0],bottomLeft[j][0]);

                int wid = topRx - botLx;

                int topRy = min(topRight[i][1],topRight[j][1]);
                int botLy = max(bottomLeft[i][1],bottomLeft[j][1]);

                int hei = topRy - botLy;

                maxSide = max(maxSide,min(wid,hei));
            }
        }
        return (1LL * maxSide * maxSide);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
