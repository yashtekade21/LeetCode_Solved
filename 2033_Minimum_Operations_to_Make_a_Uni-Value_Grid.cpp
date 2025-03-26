class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        int prevRem = -1;
        for(auto& vec:grid){
            for(auto& num:vec){
                int rem = num%x;
            
                if(prevRem != -1 && rem != prevRem){
                    return -1;
                }
                prevRem = rem;

                arr.emplace_back(num);
            }
        }

        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mid = arr[n/2];

        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += abs(mid - arr[i]);
        }

        return sum/x;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
