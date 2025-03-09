class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> vec;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums1[i],i,nums2[i]});
        }

        sort(vec.begin(),vec.end());

        vector<long long> result(n,0);
        priority_queue<int,vector<int>,greater<int>> pq;
        long long cumSum = 0;

        for(int i=0;i<n;i++){
            if(i > 0 && vec[i-1][0] == vec[i][0])
                result[vec[i][1]] = result[vec[i-1][1]];
            else
                result[vec[i][1]] = cumSum;

            pq.push(vec[i][2]);
            cumSum += vec[i][2];

            if(pq.size() > k){
                cumSum -= pq.top();
                pq.pop();
            }
        }
        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
