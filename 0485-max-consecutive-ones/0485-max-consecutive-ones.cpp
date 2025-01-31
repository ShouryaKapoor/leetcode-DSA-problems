class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ctr = 0;
        int max=0;
        for(int i = 0;i<=nums.size();i++)
        {
            if(nums[i]==1)
            {
                ctr++;
                if(max<ctr)
                {
                    max=ctr;
                }
                
            }
            else
                {
                    ctr = 0;
                }
        }
        return max;
     
    }
};