class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        int cum_sum=0,cum_val=0;
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            ans[i] = cum_sum;
            cum_val += (boxes[i] - '0');
            cum_sum += cum_val;
        }

        cum_sum = cum_val = 0;
        for(int i=n-1;i>=0;i--){
            ans[i] += cum_sum;
            cum_val += (boxes[i] - '0');
            cum_sum += cum_val;
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
