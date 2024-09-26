class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long temp = x;
        long long new_num = 0;
        while(temp != 0){
            int rem = temp%10;
            new_num = new_num*10 + rem;
            temp = temp/10;
        }
            
        return new_num == x;
    }
};
