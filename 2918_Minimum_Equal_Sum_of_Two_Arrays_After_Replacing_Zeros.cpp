class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long nums1Sum = 0,nums2Sum = 0;
        int freq0nums1 = 0,freq0nums2 = 0;

        for(auto& num:nums1){
            freq0nums1 += (num==0) ? 1 : 0;
            nums1Sum += num;
        }
        for(auto& num:nums2){
            freq0nums2 += (num==0) ? 1 : 0;
            nums2Sum += num;
        }

        long long minSumNums1 = nums1Sum + freq0nums1, minSumNums2 = nums2Sum + freq0nums2;

        if(minSumNums1 < minSumNums2 && !freq0nums1)
            return -1;
        else if(minSumNums2 < minSumNums1 && ! freq0nums2)
            return -1;
    
        return max(minSumNums1,minSumNums2);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
