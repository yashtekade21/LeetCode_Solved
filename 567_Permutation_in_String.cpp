class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int> s1arr,s2arr;
        int win = s1.length()-1;

        if(win > s2.length()) 
            return false;

        for(auto i:s1)
            s1arr[i-'a']++;

        for(int i=0;i<s2.length();i++)
        {
            s2arr[s2[i]-'a']++;
            if(i>=win){
                if(match(s1arr,s2arr))
                    return true;
                
                s2arr[s2[i-win]-'a']--;
            }
        }
        return false;
    }

    private:
    bool match(unordered_map<int,int> s1arr,unordered_map<int,int> s2arr){
        for(int i=0;i<26;i++)
            if(s1arr[i]!=s2arr[i])
                return false;
        return true;
    }
};

#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
