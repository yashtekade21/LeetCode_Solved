class Solution {
public:
    string capitalizeTitle(string title) {
        for(int i=0;i<title.length();i++){
            int prevIndex = i;
            while(i<title.length() && title[i]!= ' '){
                title[i] = tolower(title[i]);
                ++i;
            }
            if(i-prevIndex > 2)
                title[prevIndex] = toupper(title[prevIndex]);
        }
        return title;
    }
};
#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
