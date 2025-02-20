class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxHeap(nums.begin(),nums.end());
        // for(int i = 0;i<nums.size();i++)
        // {
        //     maxHeap.push(nums[i]);
        // }
        int greatest = maxHeap.top();
        maxHeap.pop();
        int secondgreatest = maxHeap.top();
        maxHeap.pop();
        return(greatest-1)*(secondgreatest -1);
    }
};