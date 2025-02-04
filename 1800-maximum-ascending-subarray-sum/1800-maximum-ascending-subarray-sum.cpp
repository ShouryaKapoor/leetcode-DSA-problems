class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];  // Initialize max sum
        int currentSum = nums[0]; // Current sum of the ascending subarray

        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { 
                currentSum += nums[i];  // Continue adding if ascending
            } else {
                maxSum = max(maxSum, currentSum); // Update max sum
                currentSum = nums[i]; // Reset sum for new subarray
            }
        }
        return max(maxSum, currentSum); // Ensure final comparison
    }
};
