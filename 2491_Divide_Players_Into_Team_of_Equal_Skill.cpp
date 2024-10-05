class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        // sort(skill.begin(), skill.end());
        // int n = skill.size();
        // long long sum = 0;
        // for (auto x : skill)
        //     sum += x;

        // int reqSum = skill[0] + skill[n - 1];
        // long long chem = 0;
        // for (int i = 0; i < skill.size(); i++) {
        //     if (skill[i] + skill[n - i - 1] != reqSum)
        //         return -1;

        //     chem += (long long)skill[i] * (long long)skill[n - i - 1];
        // }
        int totalSum = 0;
        int n = skill.size();
        unordered_map<int,int> mp;
        for(int x:skill){
            totalSum += x;
            mp[x]++;
        }

        if(totalSum % (n/2) != 0)
            return -1;

        int reqSum = totalSum / (n/2);
        long long chem = 0;
        for(auto x:skill){
            int extraReq =  reqSum - x;
            if(mp[extraReq] == 0)
                return -1;

            chem += (long long)x * (long long)extraReq;
            mp[extraReq]--;
        }
        return chem/2;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
