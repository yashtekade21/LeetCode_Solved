static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long max_score = 0;
        for(auto i:nums)
            pq.push(i);
        
        for(int i=0;i<k;i++){
            int top = pq.top();
            pq.pop();
            max_score += top;
            top = ceil(top/3.0);
            pq.push(top);
        }
        return max_score;
    }
};
