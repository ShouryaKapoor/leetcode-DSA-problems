class Solution {
public:
    string getHappyString(int n, int k) {
        string result;
        string current;
        vector<char> chars = {'a', 'b', 'c'};
        int count = 0;
        
        function<void()> backtrack = [&]() {
            if (current.size() == n) {
                count++;
                if (count == k) result = current;
                return;
            }
            
            for (char c : chars) {
                if (!current.empty() && current.back() == c) continue; // No consecutive same letters
                
                current.push_back(c);
                backtrack();
                current.pop_back();
                
                if (!result.empty()) return; // Stop early if found
            }
        };
        
        backtrack();
        return result;
    }
};
