class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        int n = start.length();

        while(i < n && j < n){
            while(i <n && start[i] == '_')
                i++;
            while(j < n && target[j] == '_')
                j++;
            
            if(i==n && j==n)
                break;
            
            if(i == n || j==n)
                return false;
            
            if (start[i] != target[j]) 
                return false;
            
            if (start[i] == 'L' && i < j)
                return false;
            
            if (start[i] == 'R' && i > j) 
                return false;
            
            i++;
            j++;         
        }
        while (i < n && start[i] == '_') 
            i++;
        while (j < n && target[j] == '_') 
            j++;
        
        return i == n && j == n;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
