class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int key;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==0&&nums[j]!=0)
                {
                   swap(nums[i],nums[j]);

                }

            }
        }
    }
};