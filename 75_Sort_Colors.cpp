class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0,mid = 0,high = nums.size()-1;

        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
