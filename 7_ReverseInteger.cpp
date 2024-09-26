class Solution {
public:
    int reverse(int x) {
        long long rem = 0,new_num=0;
        while(x!=0)
        {
            rem = x%10;
            if((new_num > INT_MAX /10) || (new_num < INT_MIN/10)){
                return 0;
            }
            new_num = (new_num*10)+rem;
            x/=10;
        }

        return new_num;
    }
};
