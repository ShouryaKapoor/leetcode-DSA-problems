class Solution {
public:
    int dfs(vector<int>& freq) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) { 
                count++;  // Count current sequence
                freq[i]--;  // Use the letter
                count += dfs(freq);  // Recursive call
                freq[i]++;  // Backtrack
            }
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char c : tiles) freq[c - 'A']++; // Count letter frequency
        return dfs(freq);
    }

};