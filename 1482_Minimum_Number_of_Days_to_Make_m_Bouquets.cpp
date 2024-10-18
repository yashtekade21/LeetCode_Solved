class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        long long totalNeeded = (long long)m*(long long)k;
        if(n < totalNeeded)
            return -1;

        while(low <= high){
            long long mid = (low+high)/2;

            if(possible(bloomDay,m,k,mid) == true)
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
private:
    bool possible(vector<int> &arr,int m,int k,int days){
        long long cnt=0,noOfBoq =0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= days)
                cnt++;
            else{
                noOfBoq += cnt/k;
                cnt = 0;
            }
        }
        noOfBoq += cnt/k;
        return noOfBoq >= m;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
