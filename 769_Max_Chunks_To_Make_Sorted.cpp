class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),count=0;
        int cumSum=0,actualSum=0;

        for(int i=0;i<n;i++){
            cumSum += arr[i];
            actualSum += i;

            if(cumSum == actualSum)
                count++;
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
