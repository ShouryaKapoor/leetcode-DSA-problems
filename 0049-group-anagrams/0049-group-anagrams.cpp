class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          unordered_map<string, vector<string>> anagramGroups;

        // Iterate through each string
        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string
            anagramGroups[sortedStr].push_back(s);   // Group by sorted string
        }

        // Collect results
        vector<vector<string>> result;
        for (auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};