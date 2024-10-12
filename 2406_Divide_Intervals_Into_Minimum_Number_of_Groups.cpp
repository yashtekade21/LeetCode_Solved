class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = intervals.size();

        for(int i=0;i<n;i++){
            mini = min(mini,intervals[i][0]);
            maxi = max(maxi,intervals[i][1]);
        }
        vector<int> track(maxi+2,0);
        // unordered_map<int,int> track;
        for(int i=0;i<n;i++){
            track[intervals[i][0]]++;
            track[intervals[i][1]+1]--;
        }
        int mingrps=0;
        int sum = 0;
        for(int i=mini;i<maxi+2;i++){
            sum += track[i];
            mingrps = max(mingrps,sum);
        }
        return mingrps;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
