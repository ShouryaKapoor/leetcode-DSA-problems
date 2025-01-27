class Solution {
public:
    bool isPalindrome(int x) {
        int t = x;
        int dig;
        long rev = 0;
        
        if(x<0)
        {
            return false;
        }
        else 
        {
            while(t>0)
            {
                dig = t%10;
                rev = rev*10 + dig;
                t/=10;
            }
            if(x == rev)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
    }
};