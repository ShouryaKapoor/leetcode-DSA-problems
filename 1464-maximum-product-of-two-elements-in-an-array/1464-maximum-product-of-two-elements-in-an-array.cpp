class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>,greater<int>> minHeap;
        for(int i = 0;i<nums.size();i++)
        {
            minHeap.push(nums[i]);
            if(minHeap.size() > 2)
            {
              minHeap.pop();   
            }
        }
        int greatest = minHeap.top();
        minHeap.pop();
        int secondgreatest = minHeap.top();
        return(greatest-1)*(secondgreatest -1);
    }
};