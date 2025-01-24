class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
   unordered_set<char> charSet; // To store unique characters in the current window
    int left = 0, maxLength = 0;

    // Iterate through the string
    for (int right = 0; right < s.size(); ++right) {
        // If the character is already in the set, shrink the window from the left
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            ++left;
        }

        // Add the current character to the set
        charSet.insert(s[right]);

        // Update the maximum length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;

    }
};