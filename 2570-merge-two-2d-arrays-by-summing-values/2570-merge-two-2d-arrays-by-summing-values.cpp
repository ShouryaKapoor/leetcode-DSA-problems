class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> valueMap;
        
        // Add values from nums1
        for (auto& pair : nums1) {
            valueMap[pair[0]] += pair[1];
        }

        // Add values from nums2
        for (auto& pair : nums2) {
            valueMap[pair[0]] += pair[1];
        }

        // Convert hashmap to sorted vector
        vector<vector<int>> result;
        for (auto& entry : valueMap) {
            result.push_back({entry.first, entry.second});
        }

        // Sort by ID (first element in subarray)
        sort(result.begin(), result.end());

        return result;
    }
};