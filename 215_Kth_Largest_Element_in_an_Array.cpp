class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto& num:nums){
            pq.push(num);
        }

        int ans;
        while(!pq.empty() && k--){
            ans = pq.top();
            pq.pop();
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
