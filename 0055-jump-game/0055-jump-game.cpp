class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        if(nums[0]==0 && n>=2)
        {
            return false;
        }
        else if(nums[0]==0 && n<2)
        {
            return true;
        }
        for(int i=0;i<n;i++)
        {
            step = nums[i];
            i=i+step;
            if(i>n)
            {
                return false;
            }

        }
        return true;
        
    }
};