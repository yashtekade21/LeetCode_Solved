class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> arr(nums.begin(),nums.end()); //O(n)
        sort(arr.begin(),arr.end()); //O(nlogn)
        unordered_map<int,int> num_group;
        int group_num = 0;
        num_group[arr[0]] = group_num;

        unordered_map<int,list<int>> groups;
        groups[group_num].emplace_back(arr[0]);

        for(int i=1;i<n;i++){        //O(n)
            if(abs(arr[i] - arr[i-1]) > limit)
                group_num++;

            groups[group_num].emplace_back(arr[i]);
            num_group[arr[i]] = group_num;
            
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){              //O(n)
            int num = nums[i];
            int grp = num_group[num];

            ans[i] = groups[grp].front();
            groups[grp].pop_front();
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
