class Solution {
public:
    int n;
    int memo[100001][3];

    int maxTwoEvents(vector<vector<int>>& events) {
       
        sort(events.begin(), events.end());

      
        n = events.size();
        memset(memo,-1,sizeof(memo));

    
        return solve(events, 0, 0);
    }

 
    int solve(vector<vector<int>>& events, int i, int cnt) {
   
        if (cnt == 2 || i >= n) return 0;

      
        if (memo[i][cnt] != -1) return memo[i][cnt];

    
        int nextIndex = bs(events, events[i][1]);

      
        int attend = events[i][2] + solve(events, nextIndex, cnt + 1);

      
        int not_attend = solve(events, i + 1, cnt);

  
        return memo[i][cnt] = max(attend, not_attend);
    }

   
    int bs(vector<vector<int>>& events, int endTime) {
        int l = 0, r = n - 1;
        int ind = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > endTime) {
                ind = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ind;
    }
};
