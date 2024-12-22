class Solution {
public:
#define P pair<int, int>
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> ans(q, -1);
        vector<vector<P>> grp(heights.size());
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < q; i++) {
            sort(queries[i].begin(), queries[i].end());
            int l = queries[i][0], r = queries[i][1];

            if (l == r || heights[l] < heights[r])
                ans[i] = r;
            else {
                int h = max(heights[l], heights[r]);
                grp[r].push_back({h, i});
            }
        }

        for(int i=0;i<heights.size();i++){
            for(auto& [q_h,q_i]:grp[i])
                pq.push({q_h,q_i});
            
            while(!pq.empty() && heights[i] > pq.top().first){
                int idx = pq.top().second;
                pq.pop();
                ans[idx] = i;
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
