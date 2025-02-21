class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        int maxFreq = 0, totalCount = 0;

        // Step 1: Count frequencies of each element
        for (int num : nums) {
            freqMap[num]++;
            maxFreq = max(maxFreq, freqMap[num]); // Track max frequency
        }

        // Step 2: Sum counts of elements with max frequency
        for (auto &[key, value] : freqMap) {
            if (value == maxFreq) {
                totalCount += value;
            }
        }

        return totalCount;
    }
};
