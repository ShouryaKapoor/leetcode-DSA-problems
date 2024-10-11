class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int j;
        vector<int> indx;
        for(i = 0;i<nums.size();i++)
        {
            for(j = i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    indx.push_back(i);
                    indx.push_back(j);
                }
            }

        }
        return indx;
    }
};