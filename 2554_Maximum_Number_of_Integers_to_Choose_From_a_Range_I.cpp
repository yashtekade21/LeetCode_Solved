class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> mp;
        for(auto i:banned)
            mp[i]++;
        
        int sum = 0,count=0;

        for(int i=1;i<=n;i++){
            if(mp[i])
                continue;
            if(sum+i <= maxSum){
                sum += i;
                count++;
            }
            else
                break;
        }
        return count;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
