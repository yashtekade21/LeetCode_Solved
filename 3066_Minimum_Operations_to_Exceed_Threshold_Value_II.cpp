class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>, greater<long long>> pq;

        for(auto& n:nums)
            pq.push(n);

        int min_op = 0;
        while(pq.top() < k){
            long long x = pq.top();
            pq.pop();

            long long y = pq.top();
            pq.pop();

            pq.push(min(x,y)*2 + max(x,y));
            min_op++;
        }

        return min_op;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
