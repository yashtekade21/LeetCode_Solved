class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n%2 != 0)    
            return false;

        stack<int> open_brac,both_brac;
        for(int i=0;i<n;i++){
            if(locked[i] == '0')
                both_brac.push(i);
            else if(s[i] == '(')
                open_brac.push(i);
            else if(s[i] == ')'){
                if(!open_brac.empty())
                    open_brac.pop();
                else if(!both_brac.empty())
                    both_brac.pop();
                else
                    return false;
            }
        }
        while(!open_brac.empty() && !both_brac.empty() && open_brac.top() < both_brac.top()){
            open_brac.pop();
            both_brac.pop();
        }

        if(!open_brac.empty())
            return false;
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
