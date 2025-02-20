class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        string result = "", s = "";

        solve(nums,n,s,result);

        return result;
    }
private:
    void solve(vector<string>& nums,int& n,string& s,string& result){
        if(s.length() == n && find(nums.begin(),nums.end(),s) == nums.end()){
            result = s;
            return;
        }
        else if(s.length() == n){
            return;
        }

        for(int num=0;num<=1;num++){
            s.push_back(num + '0');

            solve(nums,n,s,result);

            s.pop_back();
        }

        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
