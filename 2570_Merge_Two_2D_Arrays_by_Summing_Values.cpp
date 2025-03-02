class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        map<int, int> mp;

        for (auto& arr : nums1) {
            int id = arr[0];
            int val = arr[1];
            mp[id] += val;
        }

        for (auto& arr : nums2) {
            int id = arr[0];
            int val = arr[1];
            mp[id] += val;
        }

        vector<vector<int>> result;

        for (auto& [id, val] : mp) {
            result.emplace_back(vector<int>{id, val});
        }

        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


// class Solution {
// public:
//     vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
//                                     vector<vector<int>>& nums2) {
//         vector<vector<int>> result;
//         int i = 0, j = 0;
        
//         while (i < nums1.size() && j < nums2.size()) {
//             if (nums1[i][0] == nums2[j][0]) {
//                 result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
//                 i++;
//                 j++;
//             } else if (nums1[i][0] < nums2[j][0]) {
//                 result.push_back(nums1[i]);
//                 i++;
//             } else {
//                 result.push_back(nums2[j]);
//                 j++;
//             }
//         }
//         while (i < nums1.size()) {
//             result.push_back(nums1[i]);
//             i++;
//         }

//         while (j < nums2.size()) {
//             result.push_back(nums2[j]);
//             j++;
//         }

//         return result;
//     }
// };
// static const auto kds = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 0;
// }();
