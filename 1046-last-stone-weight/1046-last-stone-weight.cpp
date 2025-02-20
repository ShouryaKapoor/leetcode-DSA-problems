class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap; // create a heap
        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]); // insert into heap
        }
        while (maxHeap.size() > 1) {
            int heaviest = maxHeap.top();
            maxHeap.pop();
            int secondheaviest = maxHeap.top();
            maxHeap.pop();
            int diff = heaviest - secondheaviest;
            if (diff != 0) {
                maxHeap.push(diff);
            }
        }
        if(maxHeap.empty()) return 0;
        else return maxHeap.top();
    }
};