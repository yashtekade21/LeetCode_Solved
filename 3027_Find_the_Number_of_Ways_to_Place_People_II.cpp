class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        auto customSort = [](vector<int> points1,vector<int> points2){
            if(points1[0] == points2[0]){
                return points1[1] > points2[1];
            }
            return points1[0] < points2[0];
        };

        sort(points.begin(),points.end(),customSort);
        int ans = 0;

        for(int i=0;i<n;i++){
            int x1 = points[i][0], y1 = points[i][1];

            int maxY = INT_MIN;

            for(int j= i+1;j<n;j++){
                int x2 = points[j][0], y2 = points[j][1];

                if(y2 > y1)
                    continue; // on the upper side.

                if(y2 > maxY){
                    maxY = y2;
                    ans++;
                }
            }
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
