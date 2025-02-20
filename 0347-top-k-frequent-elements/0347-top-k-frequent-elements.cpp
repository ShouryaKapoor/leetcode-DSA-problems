class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;

    for (int num : nums) {
        freqMap[num]++;
    }
    priority_queue<pair<int,int>> maxHeap;
    for(pair<int, int> mapPair : freqMap)
    {
        maxHeap.push({mapPair.second, mapPair.first});
    }
    vector<int> ans;
    for(int i = 0; i<k; i++)
    {
        int element = maxHeap.top().second;
        maxHeap.pop();
        ans.push_back(element);
    }
    return ans;
    }
};