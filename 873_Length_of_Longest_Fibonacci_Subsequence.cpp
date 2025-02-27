class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[arr[i]] = i;
        }

        int maxSubSeqLen = 0;
        for(int k = n-1;k>=0;k--){
            for(int j = k-1;j>=0;j--){
                int len = solve(j,k,arr,mp);
                if(len >= 3)
                    maxSubSeqLen = max(maxSubSeqLen,len);
            }
        }
        return maxSubSeqLen;
    }

private:
    int solve(int j,int k,vector<int>& arr,unordered_map<int,int>& mp){
        int nextFibElement = arr[k] - arr[j];

        if(mp.find(nextFibElement) != mp.end() && mp[nextFibElement] < j){
            int i = mp[nextFibElement];
            return solve(i,j,arr,mp) + 1;  // 1 becoz to count the kth element
        }
        return 2; // last 2 elements will not be counted that why return 2
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
