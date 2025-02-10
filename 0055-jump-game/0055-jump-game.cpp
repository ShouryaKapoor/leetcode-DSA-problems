class Solution {
public:
    bool canJump(vector<int>& nums) {
        //storing the size of nums
        int n = nums.size();
        //taking answer  to be 0 as this compares the remaining jumps in the array 
        int ans = 0;
        for(int i = 0;i<n;i++) //iterating the array
        {
            if(i>ans) //if index values go over the answer range then it is a false case...insufficient steps
            {
                return false;
            }
            ans = max(ans, nums[i]+i); //updating ans value till a greater element comes after the ith element
        }
        return true; //return true when we reach the end of array
    }
};